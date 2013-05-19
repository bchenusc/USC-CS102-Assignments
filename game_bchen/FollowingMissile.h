/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef FOLLOWMISSILE
#define FOLLOWMISSILE
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"


class FollowMissile : public GameObject {

	Q_OBJECT
	
public:
	/*FollowMissile constructor. Creates a FollowMissile  that drops down on the screen targetting the player's initial position and
	* moving to that position.
	*/
	FollowMissile(int nx, int ny, int nz, QPixmap* pixmap, Player* player, double speed);
	/*FollowMissile destructor*/
	~FollowMissile();
	void HandleCollision(string type);
	
signals:
/**Signal used to change the health bar GUI display when a Health Box is absorbed by a player*/
	void changeHealth(int);
	
public slots:
	void Update(); // Called every millisecond. Handles movement and destroys health box if it goes out of range.

private:
		double speed;					//The movement speed of the health box.
		bool isMovingLeft;		//Determines which way the health box is moving for oscillation purposes.
		int initialGoToX;					//The X location of the player's initial position
		int initialGoToY;					//The Y locatio of the player's Y position
		int initialX;					//The initial X position of the missile.
		int initialY;				//The initial y position of the missile.
		
};

#endif 
