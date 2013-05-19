#ifndef PUZZLEMOVE_H
#define PUZZLEMOVE_H
#include <functional>
#include "board.h"
#include "puzzle_heur.h"

/**A class that contains the moves of the Board in potential moves used for the A* search*/

class PuzzleMove
{
 public:
  /** Constructor for starting Board of an A* search.
  * @param b A Board reference to the Board that you want the PuzzleMove to link to.
  */
  PuzzleMove(Board &b);

  /** Constructor for subsequent search boards 
  * (i.e. those returned by Board::potentialMoves() )
  * @param tile The value of the tile (int) that was moved to obtained the new board from potential move.
  * @param b A pointer to the Board that will be linked to the PuzzleMove. The Board has the altered title.
  * @param parent A pointer to the PuzzleMove that led to the new PuzzleMove being created.
  */
  PuzzleMove(int tile, Board *b, PuzzleMove *parent);

  /** Destructor deletes the dynamically allocated Board b_*/
  ~PuzzleMove();

  // Compare to PuzzleMoves based on f distance 
  /**Overloads the < operator to compare puzzle moves. Higher g's with same f scores are smaller 
  * @param p A reference to the PuzzleMove that is being compared with this PuzzleMove.
  */
  bool operator<(const PuzzleMove& p) const;
  /**Overloads the > operator to compare PuzzleMoves.
  * @param p A reference to the PuzzleMove that is being compared with this PuzzleMove.
  */
  bool operator>(const PuzzleMove& p) const;
    /**Overloads the == operator to compare PuzzleMoves.
  * @param p A reference to the PuzzleMove that is being compared with this PuzzleMove.
  */
  bool operator==(const PuzzleMove& p) const;

  // Data members can be public
 public:
  int tileMove_;  // tile moved to reach the Board b
  Board *b_;      // Pointer to a board representing the updated state
  int g_;         // distance from the start board
  int h_;         // heuristic distance to the goal
  PuzzleMove *prev_;  // Pointer to parent PuzzleMove
};


// Leave this alone and don't touch it!
struct PuzzleMoveGreater : 
  public std::binary_function<const PuzzleMove*, const PuzzleMove*,bool>
{
  bool operator()(const PuzzleMove *m1, const PuzzleMove *m2) const
  {
    return *m1 > *m2;
  }
};

#endif
