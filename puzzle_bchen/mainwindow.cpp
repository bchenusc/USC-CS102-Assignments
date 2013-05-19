#include "mainwindow.h"
#include "puzzle_solver.h"


/** The MainWindow constructor.
 * Sets style to QPlastiqueStyle of the Window. 
 * Creates the outer layer that contains all the buttons, scene, view, subplayers, groupboxes, and buttons.
 * Basically...everything you see.
 * Alsos connects the gui items to the slots they need to correspond with.
 */
MainWindow::MainWindow()  {
		//Makes Application beautiful
    QStyle* motif = new QPlastiqueStyle();
    
    //First time we are running the game.
    firstTimeRunningGame = true;
    solved= false;
    aTileIsMoving=false;
    //Set the heuristic to zero because none of the radio buttons are pressed.
    heur =0;
    
    //We need a scene and a view to do graphics in QT
    mainWin = new QGridLayout();	//This is your main layout bg window.
    scene = new QGraphicsScene(0,0,WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    view = new QGraphicsView(scene);
    
   
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2+2, WINDOW_MAX_Y*2+2);
    view->setWindowTitle( "Puzzle My Nuzzle");
    mainWin->addWidget(view, 0, 1, 6, 1);
    
    
    //Make a groupbox for the text
    QGroupBox* textGroupBox = new QGroupBox(tr("Options"));
    QGridLayout* textLayout = new QGridLayout();	//This is a layout that holds your 3 text fields.
  	textGroupBox->setLayout(textLayout);
  	textGroupBox->setStyle(motif);
  	mainWin->addWidget(textGroupBox, 1, 2, 1, 1);
    //Create three text boxes
    textSize = new QLineEdit();
    textMoves = new QLineEdit();
    textSeed = new QLineEdit();
    //Place the text boxes.
    textLayout->addWidget(textSize, 1, 2, 1,1);
    textLayout->addWidget(textMoves, 2, 2, 1,1);
    textLayout->addWidget(textSeed, 3, 2, 1, 1); 
    //Create the text to label each text fields.
    QLabel *sizeLabel = new QLabel("Board Size");
    QLabel *startingMovesLabel = new QLabel("Initial Moves");
    QLabel *seedLabel = new QLabel("Seed");
    //Place the labels in the layout.
		textLayout->addWidget(sizeLabel,1,1,1,1);
		textLayout->addWidget(startingMovesLabel,2,1,1,1);
		textLayout->addWidget(seedLabel,3,1,1,1);
		
		//Make a groupbox for the radio buttons:
		QGroupBox* heurGroup = new QGroupBox(tr("Heuristics"));
		QGridLayout* heurLayout = new QGridLayout(); //Radio button layout.
		heurGroup->setLayout(heurLayout);
  	heurGroup->setStyle(motif);
  	mainWin->addWidget(heurGroup, 3, 2, 1, 1);
		//Create your radio buttons.
		manhattan = new QRadioButton("Manhattan Heuristic");
		outOfPlace = new QRadioButton("OutOfPlace Heuristic");
		heurLayout->addWidget(manhattan, 4, 1, 1, 1);
    heurLayout->addWidget(outOfPlace, 4, 2, 1, 1);
    manhattan->setStyle(motif);
    outOfPlace->setStyle(motif);
    QObject::connect(manhattan, SIGNAL(clicked()), this, SLOT(toggleHeur()));
		QObject::connect(outOfPlace, SIGNAL(clicked()), this, SLOT(toggleHeur()));	    
    
    //Create a groupbox for the start and quit buttons
    QGroupBox* controlGroup = new QGroupBox(tr("Controls"));
		QGridLayout* controlLayout = new QGridLayout(); //Radio button layout.
		controlGroup->setLayout(controlLayout);
  	controlGroup->setStyle(motif);
    //Create Start and Quit Button.
    QPushButton *start = new QPushButton("Start");
    	QObject::connect(start, SIGNAL(clicked()), this, SLOT(start()));
    start->setStyle(motif);
    controlLayout->addWidget(start, 4, 1, 1, 1);
    //Quit Button
    QPushButton *quit = new QPushButton("Quit");
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    quit->setStyle(motif);
    controlLayout->addWidget(quit, 4, 2, 1, 1);
    mainWin->addWidget(controlGroup, 2, 2, 1, 1);
    
    //Create a layout for the cheat and its solution box.
  	//Create a cheat button with a spot for the cheat to come out.
    QGroupBox* cheatBox = new QGroupBox(tr("Cheats"));
		QGridLayout* cheatLayout = new QGridLayout(); //Radio button layout.
		cheatBox->setLayout(cheatLayout);
  	cheatBox->setStyle(motif);
    //Create Button for cheat
    QPushButton *hint = new QPushButton("Hint");
    QObject::connect(hint, SIGNAL(clicked()), this, SLOT(cheat()));
    hint->setStyle(motif);
    cheatLayout->addWidget(hint, 1, 1, 1, 1);
    //Add a solutions box.
    viewSolutions = new QListWidget();
    cheatLayout->addWidget(viewSolutions,2,1,1,4);
    mainWin->addWidget(cheatBox, 4, 2, 1, 1);
    
    //Add Error messaging system
    QGroupBox* errBox = new QGroupBox(tr("System"));
		QGridLayout* errlayout = new QGridLayout(); //Radio button layout.
		errBox->setLayout(errlayout);
  	errBox->setStyle(motif);
  	errorSpace = new QTextEdit();
  	errorSpace->setReadOnly(true);
  	errlayout->addWidget(errorSpace,1,1,1,1);
    mainWin->addWidget(errBox,7,1,6,2);
		
		setLayout(mainWin);
}

/** Start function: 
 * First clears everything on the screen: view, error output, heuristic.
 * Then checks if the input parameters in the text lines are valid appropriate integers.
 * Then creates a board that is based on the input parameters.
 * If the board is already solved. Change each tile so that they spell out You Win!!!!!!!!!
 */
void MainWindow::start(){
//------------------------------DO NOT TOUCH: ERROR HANDLING-----------------------------------------------------
	//clears everything on screen
	errorSpace->clear();
	if (!firstTimeRunningGame){
		for (int i=0; i<size; i++){
			scene->removeItem(tileArray[i]);
			delete tileArray[i];
		}
	}
	viewSolutions->clear();
	
	//Check if 3 text fields have been satisfied with valid integers 3x3 or 4x4 and the first text field is a square number.
	int initMoves, seed;
	bool errorFound = false;
	
	size = textSize->text().toInt();
	initMoves = textMoves->text().toInt();
	seed = textSeed->text().toInt();
	if (!checkIfInt(textSize->text().toStdString())){
		errorSpace->append("Error: Invalid board size. Please enter 9 or 16.");
		errorFound=true;
	}
	if (!checkIfInt(textMoves->text().toStdString())){
		errorSpace->append("Error: Invalid initial moves. Please enter a number greater than 0.");
		errorFound=true;
	}
	if (!checkIfInt(textSeed->text().toStdString())){
		errorSpace->append("Error: Invalid seed. Please enter a valid integer.");
		errorFound=true;
	}
	//size must be a 3x3 or 4x4
	if (size!=9 && size!=16){
		errorSpace->append("Error: Invalid board size. Please enter 9 or 16.");
		errorFound = true;
	}
	//Error handling for intial moves. if initial moves is not set. defaults to zero.
	//Otherwise if the intial moves is negative then put an error.
	if (!textMoves->isModified()){
			errorSpace->append("Warning: Inital moves not set. Defaulting to 0.");
	}
	else if (initMoves<0){
			errorSpace->append("Error: Invalid initial moves. Please enter a number greater than 0.");
			errorFound = true;
	}
	
	//Error handling for seed. if the seed is not set. Defaults to zero. Outputs a warning.
	if (!textSeed->isModified()){
		errorSpace->append("Warning: Seed not set. Defaulting to 0.");
	}
	
	//If any error is found then break out of the start funciton.
	if (errorFound==true){
		firstTimeRunningGame = true;
		startClicked=false;
		return;
	}
//----------------------------------------------------------------------------------------------------------------
	//Initializes the board
	b_ = new Board(size, initMoves, seed);
	firstTimeRunningGame = false;
	solved=false;
	startClicked=true;

	//Initializes the GUI Tile in an array that corresponds to the board.
	tileArray = new GUITile*[size];

	
	int gx, gy, gw, gh, valueCounter=0;
	gw = WINDOW_MAX_X/sqrt(size);
	gh = WINDOW_MAX_Y/sqrt(size);
	for (int j=-1; j<sqrt(size)-1; j++){
		gy = WINDOW_MAX_Y/sqrt(size)*(j+1)+WINDOW_MAX_Y/2;
		for(int i=0; i<sqrt(size);i++){
			//Creates each tile!
			gx = WINDOW_MAX_X/sqrt(size)*i+WINDOW_MAX_X/2;
			tileArray[valueCounter] = new GUITile(gx,gy, gw, gh, b_->getTiles()[valueCounter]);
			//Connect a bunch of signals to each individual tiles.
			QObject::connect(tileArray[valueCounter], SIGNAL(mouseIsPressed(int)), this, SLOT(MainWindowmoveTile(int)));
		  QObject::connect(tileArray[valueCounter]->timer, SIGNAL(timeout()), tileArray[valueCounter], SLOT(handleTimer()));
		  QObject::connect(tileArray[valueCounter], SIGNAL(toggleTileInGridIsMoving(bool)), this, SLOT(toggleTileMoving(bool)));
			scene->addItem(tileArray[valueCounter]);
			valueCounter++;
		}
	}
	//creates a background to hide the blank tile.
	bgBox = new QGraphicsRectItem(WINDOW_MAX_X/2,WINDOW_MAX_Y/2, (int)sqrt(size)*gw, (int)sqrt(size)*gh);
	scene->addItem(bgBox);
	
	//Checks if board is already solved
		//if the board is solved then the variable solved == true;
	if (b_->solved()){
			win();
	}
}
/** Checks if the clicked tile is movable. If it is movable then move it in the board and move the GUI to the appropriate spot.
*	Swaps blank tile and the clicked tile if possible.
* @param tile The tile in question that wants to be moved! In this case it is the clicked tile.
*/
void MainWindow::MainWindowmoveTile(int tile){
	if (aTileIsMoving){return;}
	//Check if the move is possible by checking the move on the board first.
	int tempBlankX, tempBlankY;
		GUITile* blankTile = tileArray[0];
		GUITile* clickedTile = tileArray[0];
		int bTileIndex=0, cTileIndex=0;
	if (b_->move(tile)&&!solved){
	//Find blank tile location on qt
	//Find tile location on qt
		for (int i=0; i<size; i++){
			if (tileArray[i]->getVal() == 0)
			{	//Searching for the blank tile.
				blankTile = tileArray[i];
				bTileIndex = i;
			}
			
			if (tileArray[i]->getVal() == tile){
			//Searching for the clicked tile.
				clickedTile = tileArray[i];
				cTileIndex=i;
			}
		}
		//Swap the two tiles (blank and clicked)
		//First store the blank tile's x and y coordinates.
		tempBlankX = blankTile->getX();
		tempBlankY = blankTile->getY();
		
		//Then move the blank tile to the coordinates of the clicked tile.
		blankTile->moveTile(clickedTile->getX(), clickedTile->getY());
		//Now move the clicked tile to the temorarily stored x and y values of blank tile.
		clickedTile->moveTile(tempBlankX, tempBlankY);
		aTileIsMoving = true;
		
		tileArray[bTileIndex] = clickedTile;
		tileArray[cTileIndex] = blankTile;
	}
	//if the board is solved then the variable solved == true;
	//Checks if board is already solved
	//if the board is solved then the variable solved == true;
	if (b_->solved()){
		win();
	}
}
/** This function is called when the player wins the game. It will change all the tiles so that each tile 
* displays a character from the string "You Win!"
*/
void MainWindow::win(){
		 solved=true;
		 startClicked=false;
		 //Goes through all the values and changes each letter.
		 std::string s3 = "YOUWIN!!!";
		 std::string s4 = "    YOU WIN!    ";
		 int sCounter=0;
		 for(int i=0; i<size; i++){
		 
		 if (sqrt(size)==4){
		 		if(sCounter>=16){sCounter=0;}
		 			tileArray[i]->setText(s4[sCounter]);
		 			sCounter++;
		 }
		 else {if (sCounter>=9){sCounter=0;}
		 		tileArray[i]->setText(s3[sCounter]);
		 		sCounter++;
			 }
		}
}
/** This function is used to change whether a tile is currently animating to its position or not. aTileIsMoving variable 
* needs to be set true when a tile is animating and false if no tile is animating.
* @param toggle Set this variable to true or false to change aTileIsMoving variable.
*/
void MainWindow::toggleTileMoving(bool toggle){
	aTileIsMoving = toggle;
}
/** This function checks which radio button is pressed. If manhattan is checked, this function sets an integer variable
* linked to the value of the manhattan code in the Heuristic struct. Else 'heur' is set to out of place. Use the
* 'heur' to determine which heuristic you are using after calling toggleHeur();
*/
void MainWindow::toggleHeur(){
	if (manhattan->isChecked()){
		this->heur = MANHATTAN;
	}else this->heur=OUTOFPLACE;

}
/** This function creates the cheat in the game. First it checks whether the game has already been won. If it has been won,
* then output an error saying the game has already been won. If start has never been clicked and no board is instantiated,
* output an error. If no heuristic is selected then output an error. Creates a PuzzleHeuristic and PuzzleSolver objects
* and creates a list of solutions using the run([heuristic]) function. Stores the list of solutions and outputs them in the 
* cheat window.
*/
void MainWindow::cheat(){
	//Error handling
	viewSolutions->clear();
	if (solved){
		errorSpace->append("Error: Stop being an idiot. You already won.");
		return;
	}
	if (!startClicked){
		errorSpace->append("Error: No Game Start :<");
		return;
	}
	if (heur ==0 && startClicked){
		errorSpace->append("Error: You must select a Heuristic.");
	return;
	}
	
	//Create Heuristic and PuzzleSolver pointer which will be initialized when -1 is pressed.
  PuzzleHeuristic* heuristic;
  PuzzleSolver* solver;
	  	//Implement cheat when -1 is pressed.
  		//Dynamically allocate the solver and the heuristic **don't forget to delete after use**
  		solver = new PuzzleSolver(*b_);
  		//Manually change the below
  		if (heur==MANHATTAN){
  		heuristic = new ManhattanHeuristic();
  		}else 
  		heuristic = new OutOfPlaceHeuristic();
  		
  		//Run the solver with the given heuristic. Manually uncomment 'heur' to change heuristics.
  		int listSize = solver->run(heuristic);
		//Give the Player the correct solution to win the game.
  		
  		for (int i=listSize-1; i>=0; i--){
  			//Traverse through the mylist solutions stored in the solver class and print it out backwards.
  			//Print it out backwards because solver initializes the list in reverse order due to code logic.
  			QString number = QString::number(solver->getSolution()[i]);
  			viewSolutions->addItem(number);
  		}
  		viewSolutions->insertItem(0,"Try this sequence: ");

  		//Delete the solver and the heuristic because you don't need them anymore.
  		delete heuristic;
  		delete solver;
	
}
/** This function checks if the parameter s is a valid integer.
* @param s The string you want to check if it is a valid integer or not.
* @return Boolean value that returns true if the string s is a valid integer and false if it is not.
*/
bool MainWindow::checkIfInt(string s){
	if (s[0]!='-'){
		if (!(s[0]<='9' && s[0]>='0')){
			return false;
		}
	}
	
	for (unsigned int i=1; i<s.length(); i++){
		if (!(s[i]<='9' && s[i]>='0')){
			return false;
		}
	}
	return true;
}
/** Destructor does nothing b/c we do not need to implement memory deallocation.
*/
MainWindow::~MainWindow()
{

}
