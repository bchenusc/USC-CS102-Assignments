#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H


class PuzzleHeuristic
{
 public:
 /** Virtual function, overrideable function allowing for different implemntations of heurisitic calculation functions.
* @param tiles A pointer to the tiles of the board that needs its heuristic calculated.
* @param size The size of the tile list that is having its Heuristic computed.
* @return Returns the calculated heuristic of the board.
*/
  virtual int compute(int *tiles, int size) = 0;
};


// Define actual Heuristic Classes here
class ManhattanHeuristic : public PuzzleHeuristic
{
  public:
  /** Manhattan heuristic computation. Computes the heuristic of the board by analyzing all the tiles and how far they are from
* the position they should be. For example if the tiles are in proper order in a 3x3 matrix and only value 7 and the blank
* tile then the algorithm will calculate how far the tile value 7 at index 0 is from its ideal position at index 7 by looking
* at the horizontal and verticle moves necessary to displace the value 7 tile.
* @param tiles A pointer to the tiles of the board that needs its Manhattan heuristic calculated.
* @param size The size of the tile list that is having its Manhattan Heuristic computed.
* @return Returns the calculated heuristic of the board.
*/
    int compute(int *tiles, int size);
};

class OutOfPlaceHeuristic : public PuzzleHeuristic
{
  public:
  /** Out of Place Heuristic. Computes the heuristic of the board by adding one to the heuristic if the tile is out of place from the index it should be at.
* @param tiles A pointer to the tiles of the board that needs its Out of Place heuristic calculated.
* @param size The size of the tile list that is having its Manhattan Heuristic computed.
* @return Returns the calculated heuristic of the board.
*/
    int compute(int *tiles, int size);
};


#endif
