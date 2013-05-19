#include "puzzle_move.h"



PuzzleMove::PuzzleMove(Board &b){
  tileMove_ = 0;  // tile moved to reach the Board b
  b_ = new Board(b);    // Pointer to a board representing the updated state
  g_ = 0;         	// distance from the start board
  h_ = 0;		// heuristics
  prev_= NULL;  	// Pointer to parent PuzzleMove
}

PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent){
  tileMove_ = tile; 		// tile moved to reach the Board b
  b_ = new Board(*b);	        // Pointer to a board representing the updated state
  g_ = parent->g_+1;      	// distance from the start board
  h_ = 0; 		 	// heuristic	
  prev_= parent;  		// Pointer to parent PuzzleMove
}

PuzzleMove::~PuzzleMove(){
  delete b_;
}

bool PuzzleMove::operator==(const PuzzleMove& p) const{
	//If p and the current PuzzleMove have the same private variables than they are equal.
  	if (p.tileMove_ == tileMove_ && p.b_ == b_ && p.g_ == g_ && p.h_ == h_ && p.prev_ == prev_){
  		return true;
  	}
  	else return false;
}


// Compare to PuzzleMoves based on f distance (needed for priority queue)
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

