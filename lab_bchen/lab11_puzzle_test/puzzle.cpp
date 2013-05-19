#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include <cmath>
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;


/*int main(int argc, char *argv[])
{
  if(argc !=4){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }

  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);/*
  
  
 //if the argument for size is not a square number then break out of the loop.
  if (abs(sqrt(size) - int(sqrt(size))) > 0){
  	cout<<"Size not a square...Program Ending..."<<endl;
  	return 0;
  }
 
  //Create a new board.
  Board b(size,initMoves,seed);
  
  //Create Heuristic and PuzzleSolver pointer which will be initialized when -1 is pressed.
  PuzzleHeuristic* heur;
  PuzzleSolver* solver;

  do{
  //Logic:
  //1. Print the board that is created.
  //2. If the board is not already solved then continue to play otherwise terminate program.
  //3. If board is not solved then ask the user to enter a tile on the board or -1 to get a cheat.
  //4. Test a fail case for input.
  //5. If the user input is valid on the board then move the blank tile and the tile.
  //6. If the user input is -1 then run the cheat using the solver and the heuristic.
  	cout<<b<<endl;
  	if (b.solved()){break;}
  	cout<<"Enter tile to move or -1 for cheat: ";
  	int switchNum=0;
  	
  	//Asks what user wants to switch.
  	cin>>switchNum;
  	//If your cin is not a number the cin will fail.
  	if (cin.fail()){
  		//Clear the fail bit and handle all problems. Then ask the user to enter a tile again.
  		cin.clear();
  		cin.ignore(1024, '\n');
  		continue;
  	}
  	if (switchNum>=0 && switchNum<size){
  	//If the number the user inputs is valid then run the move function.
  		b.move(switchNum);
  	}
  	if (switchNum==-1){
  		//Implement cheat when -1 is pressed.
  		//Dynamically allocate the solver and the heuristic **don't forget to delete after use**
  		solver = new PuzzleSolver(b);
  		//Manually change the below
  		heur = new ManhattanHeuristic();
  		//heur = new OutOfPlaceHeuristic();
  		
  		//Run the solver with the given heuristic. Manually uncomment 'heur' to change heuristics.
  		int listSize = solver->run(heur);
		//Give the Player the correct solution to win the game.
  		cout<<"Try this sequence: ";
  		for (int i=listSize-1; i>=0; i--){
  			//Traverse through the mylist solutions stored in the solver class and print it out backwards.
  			//Print it out backwards because solver initializes the list in reverse order due to code logic.
  			cout<<solver->getSolution()[i]<<" ";
  		
  		}
  		cout<<endl;
  		//Print out the number of expansions intialized in the solver class.
  		cout<<"(Expansions = "<< solver->getNumExpansions()<<")"<<endl;
  		//Delete the solver and the heuristic because you don't need them anymore.
  		delete heur;
  		delete solver;
  	}
  	//Clear the fail bit and handle any problems with cin just in case the user types multiple numbers.
  	cin.clear();
  	cin.ignore(1024, '\n');
  }
  //Keep running this loop until the puzzle is solved.
  while(b.solved()==false);
  //Finally print the board out at the end when the player has won.
  cout<<b<<endl;
  return 0;
} */
