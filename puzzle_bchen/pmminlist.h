#ifndef PMMINLIST_H
#define PMMINLIST_H
#include <list>

/**
 * PMMinList implements a sorted list of PuzzleMoves
 * based on their f-score (from smallest to largest)
 */
class PMMinList 
{
 public:
  
  PMMinList();
  ~PMMinList();
  /** Returns the size of items in the list */
  int size() const { return slist_.size(); }
  /** Returns true if the list is empty */
  bool empty() const { return slist_.empty(); }
/** Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
  void push(PuzzleMove* pm);
  /**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
  void pop();
  /**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return reference to the minimum-scored PuzzleMove*
 */
  PuzzleMove* top();
  
 private:
  /** the sorted list */
  std::list<PuzzleMove*> slist_;
};

#endif
