/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef DEADLYHAMSTER
#define DEADLYHAMSTER
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"
#include "Missile.h"


class DeadlyHamster : public GameObject {

	Q_OBJECT
	
public:
	/*DeadlyHamster constructor. Creates a Hamster that moves left along the ground.*/
	DeadlyHamster(int nx, int ny, int nz, QPixmap* pixmap, double speed);
	/*Default destructor*/
	~DeadlyHamster();
	/*If collides with a "Player" type object, then the Hamster will destroy itself and add dammage to the player.*/
	void HandleCollision(string type);
	
signals:
	/**A signal that tells the main game to increment the player's score by a certain amount. */
	void addScore(int);
	
public slots:
	/*Update is called every millisecond. Handles the leftward movement of the hamster and destruction of the hamster if it goes offscreen.*/
	void Update();
	/*Collision is called every millisecond. Handles the collision of the hamster with the Player's missile.*/
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
private:
	  double speed; //The speed at which the player moves.
		
};

#endif 
