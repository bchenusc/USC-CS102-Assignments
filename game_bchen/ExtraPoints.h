/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef EXTRAPOINTS
#define EXTRAPOINTS
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"


class ExtraPoints : public GameObject {

	Q_OBJECT
	
public:
	/*ExtraPointsconstructor. Creates a ExtraPoints that drops down on the screen.*/
	ExtraPoints(int nx, int ny, int nz, QPixmap* pixmap, double speed);
	/*ExtraPointsdestructor*/
	~ExtraPoints();
	/*Sets a reference to the player. Boost_Health needs this reference to edit the player's health.*/
	void setPlayerRef(Player* player);
	
signals:
/**Signal used to change the health bar GUI display when a Health Box is absorbed by a player*/
	void addScore(int);
	
public slots:
	void Update(); // Called every millisecond. Handles movement and destroys health box if it goes out of range.
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);	 // Called every millisecond. Handles collision with player and/or player bullets.

private:
		Player* playerRef;		//A reference to the player to change player's health.
		double speed;					//The movement speed of the health box.
		bool isMovingLeft;		//Determines which way the health box is moving for oscillation purposes.
		int initialX;					//The initial X spawn position of the health box used for oscillation purposes.
		int initialY;					//The initial Y spawn position of the health box used for oscillation purposes.
		
};

#endif 
