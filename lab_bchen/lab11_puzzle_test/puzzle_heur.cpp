#include "puzzle_heur.h"
#include <cmath>
#include <cstdlib>


/* Manhattan heuristic computation. Computes the heuristic of the board by analyzing all the tiles and how far they are from
* the position they should be. For example if the tiles are in proper order in a 3x3 matrix and only value 7 and the blank
* tile then the algorithm will calculate how far the tile value 7 at index 0 is from its ideal position at index 7 by looking
* at the horizontal and verticle moves necessary to displace the value 7 tile.
* @param tiles A pointer to the tiles of the board that needs its Manhattan heuristic calculated.
* @param size The size of the tile list that is having its Manhattan Heuristic computed.
* @return Returns the calculated heuristic of the board.
*/
int ManhattanHeuristic::compute(int *tiles, int size){
	int heur = 0;
	for (int i=0; i<size; i++){
		//tiles[i] is where the tile should b.
		//i is the tile location now.
		if(tiles[i]!=i && tiles[i]!=0){
		//Add vertical and horizontal respectively
			//Verticle computation
			heur+= abs(int(tiles[i]/(int)sqrt(size)) - int(i/(int)sqrt(size)));
			//Horizontal computation
			heur+= abs(int(tiles[i]%(int)sqrt(size)) - int(i%(int)sqrt(size)));
		}
	}
	return heur;
}
/* Out of Place Heuristic. Computes the heuristic of the board by adding one to the heuristic if the tile is out of place from the index it should be at.
* @param tiles A pointer to the tiles of the board that needs its Out of Place heuristic calculated.
* @param size The size of the tile list that is having its Manhattan Heuristic computed.
* @return Returns the calculated heuristic of the board.
*/
int OutOfPlaceHeuristic::compute(int *tiles, int size){
	int heur=0;
	for (int i=0; i<size; i++){
	//Loop through the entire list.
		if (tiles[i]!=i && tiles[i]!=0){
			//if a tile is not in the correct place then add one to the heuristic.
			heur++; 
		}
	}
	return heur;
}
