#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include "board.h"
#include "puzzle_move.h"
#include "puzzle_heur.h"
#include "mylist.h"

class PuzzleSolver
{
 public:
  //*** Typedef for the closed-list set.  Declare your closed list variable as
  //***   BoardSet closedlist; 
  //*** when you write your code for the run() funciton
  typedef std::set<Board*, BoardLessThan> BoardSet;

  /** Constructor (makes a copy of the Board and stores it in _b
  * @param b A reference to the Board that needs to be copied and stored in as b_.
  */
  PuzzleSolver(const Board &b);

  /**Destructor that deletes the dynamically allocated b_.  */
  ~PuzzleSolver();

  /** Run the A* search returning -1 if no solution exists or
  *  the number of moves in the solution.
  * @param ph A pointer to the PuzzleHeuristic that is going to be implemented on the board. Currently either Manhattan or OutOfPlace
  * @return Returns the # of moves in the solutions or returns -1 if no solution.
  */
  int run(PuzzleHeuristic *ph);

 
 /**Returns the solution list.
 *	@return Returns a Mylist of int solutions.
 */ 
  MyList<int>& getSolution(){ return solutions;}
 

  /**Return how many expansions were performed in the search
  * @return Returns how many expansions were performed in the search.
  */
  int getNumExpansions();

 private:
  Board* b_;
  int expansions_;
  //**** Declare a List to store your solutions sequence of tiles to move
  MyList<int> solutions;
};

#endif
