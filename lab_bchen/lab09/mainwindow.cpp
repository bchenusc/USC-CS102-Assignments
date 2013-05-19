#include "mainwindow.h"
#include <QPushButton>

//zhengcao@usc.edu
void MainWindow::handleTimer() {
rectangleCounter++;
    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    
    if (rectangleCounter==500){
    rectangleCounter=0;
    QBrush redBrush(Qt::red);
    //First 2 arguments are the x, y, of the upper left of the rectangle.
    //The second 2 arguments are the width and height
    //The last 2 arguments are the velocity in the x, and y, directions
    item = new BouncingRectangle( rand()%245+5, rand()%245+5, 20.0, 20.0, rand()%4+1, rand()%4+1);
    QPixmap* pixel = new QPixmap("picture.png");
    QLabel* label = new QLabel(view);
    
    label->setPixmap(*pixel);
    label->show();
    labels.push_back(label);
    pixels.push_back(pixel);
    
    
    //int color=rand()%4;
    int color=9;
    
    switch (color){
    	case 0: redBrush.setColor(Qt::green);break;
    	case 1: redBrush.setColor(Qt::blue);break;
    	case 2: redBrush.setColor(Qt::yellow);break;
    	case 3: redBrush.setColor(Qt::red);break;
    	default: redBrush.setColor(Qt::white);break;
    }
    
    item->setBrush( redBrush );
    item->setPen(Qt::NoPen);
    scene->addItem( item );
    rectangles.push_back(item);
    }
    for (unsigned int i=0; i<rectangles.size(); i++){
    	rectangles[i]->move( WINDOW_MAX_X, WINDOW_MAX_Y );
    	labels[i]->move(rectangles[i]->getX()+100, rectangles[i]->getY()+100);
    	
    }
}

MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    rectangleCounter=0;
    //Create a pause/unpause button.
    QPushButton *pause = new QPushButton("Pause", view);
    QObject::connect(pause, SIGNAL(clicked()), this, SLOT(toggleTimer()));
    pause->show();

    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));

    timer->start();

}

void MainWindow::toggleTimer(){
	if (timer->isActive()){
	  timer->stop();
	}
	else timer->start();
}

void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    timer->start();

    //This is how we get our view displayed.
    view->show();
}

MainWindow::~MainWindow()
{
    timer->stop();
    for (unsigned int i=0; i<rectangles.size(); i++){
    	delete pixels[i];
    	delete rectangles[i];
    	delete labels[i];
    }
    
    delete timer;
    //delete item;
    delete scene;
    delete view;
}

