/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef BOOSTHEALTH
#define BOOSTHEALTH
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"


class Boost_Health : public GameObject {

	Q_OBJECT
	
public:
	/*Boost_Health constructor. Creates a Health Box that drops down on the screen.*/
	Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed);
	/*Boost_Health destructor*/
	~Boost_Health();
	/*Sets a reference to the player. Boost_Health needs this reference to edit the player's health.*/
	void setPlayerRef(Player* player);
	
signals:
/**Signal used to change the health bar GUI display when a Health Box is absorbed by a player*/
	void changeHealth(int);
	
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
