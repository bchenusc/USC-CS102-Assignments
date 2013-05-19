#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"
#include <vector>

using namespace std;


PuzzleSolver::PuzzleSolver (const Board &b){
	//Makes a copy of the original board and stores it in b_
	//Initializes the original expansions to 0
	b_ = new Board(b);
	expansions_=0;
}

PuzzleSolver::~PuzzleSolver(){
	//Deletes the dynamically allocated b_
	delete b_;
}

int PuzzleSolver::run(PuzzleHeuristic *ph){
	//Score puzzle moves
	
	//Generate an open list and closed list.
	PMMinList openList;
	BoardSet closedList;
	vector<PuzzleMove*> garbage;
	int numberMoves = 0;
	
	//A* Algorithm
	//Add the start state(start move) to the open list.
	PuzzleMove* move = new PuzzleMove(*b_);
	openList.push(move);
	//Add the starting board to the closed list
	closedList.insert(b_);
	garbage.push_back(move);
	//while the open list is not empty and a solution has not been found.
	
	while(!openList.empty() && b_->solved() == false){
		
		//Pop the min value from PMMinList and put it in move.
		move = openList.top(); //stores lowest score to move.
		openList.pop();
		
		//Add move's board to the garbage list.
		//garbage.push_back(move);
		
		//if move is goal node then trace path backwards
		//Make a counter of how many moves.
		
		if (move->b_->solved()){
		
			while(move->prev_!=NULL){
				numberMoves++;
				solutions.push_back(move->tileMove_);
				move = move->prev_;
			}
			
			for (unsigned int i= 0; i<garbage.size();i++){
			//Deallocate everything in the garbage list.
				delete garbage[i];
			}
			//This is where the actual return is for the number of moves in the solutions list.
			return numberMoves;
		}
		//Generate next potential moves
  		std::map<int, Board*> map = move->b_->potentialMoves(); 

  		for (std::map<int, Board*>::iterator it = map.begin(); it!=map.end(); ++it){
  			PuzzleMove* s = new PuzzleMove(it->first, it->second, move);
  			
  			//For each potential move, if the board (s) is not in the closed
  			
  			//Check if in closed loop
  			bool inClosedLoop = false;
  			BoardSet::iterator iter = closedList.begin();
  			while (iter!= closedList.end()){
  				if (**iter == *(s->b_)){
  					inClosedLoop=true;
  					break;
  				} 
  				++iter;
  			}
  			//if not in the loop
  			if (!inClosedLoop){ 
  			
  				//Compute f values for each potential move.
  				s->h_ = ph->compute(s->b_->getTiles(), s->b_->getSize());
  				
  				//Add the board of s to the closed set.
  				closedList.insert(s->b_);
  				openList.push(s);
  				expansions_++;
  				
  			}
  			//push EVERYTHING into the garbage list. Note the first thing isn't placed in the garbage list so
  			//will manually deallocate it later.
			garbage.push_back(s);
  			delete it->second;
  		}
  		
	}
	//Deallocate the first thing.
	delete move;
	return -1;
}

int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
