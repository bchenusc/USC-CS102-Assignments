/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef ENEMY
#define ENEMY
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"
#include "Missile.h"


class Enemy : public GameObject {

	Q_OBJECT
	
public:
	/*Enemy constructor that constructs an enemy with x,y coordinates and z depth with a given picture and/or animation)*/
	Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed, double shootSpeed);
	/*Enemy constructor that constructs an enemy with x,y coordinates and z depth with a given picture. No animation!)*/
	Enemy(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed, double shootSpeed);
	/*Default enemy constructor*/
	~Enemy();
	/*Returns the Health of the enemy*/
	int getHealth();
	/*Sets the health of the enemy*/
	void setHealth(int health);
	/*Sets the number of bullets an enemy can spawn at any given time. The game increments the number of bullets every 15 seconds*/
	void setNumOfBullets(int num);
	/*Sets the rate at which the enemy can fire his bullets.*/
	void setRSpawnBulletCounter(int num);
	/*Gives the Enemy a reference to the player to add score when the enemy is destroyed*/
	void setPlayerRef(Player* player);
	
signals:
/** A signal that tells the game to add a set score to the player. The enemy gives +25 to the player when destroyed.*/
	void addScore(int);
	
public slots:
/*Update function is called every millisecond. Handles the animation of the enemy if there is one and the movement from left to right
* or right to left depending on where the enemy spawns. Also destroys the enemy if the enemy goes offscreen.
*/
	void Update();
/* Collision function is called every millisecond. Handles the collision between Enemy and player bullets. If a player bullet hits the enemy,
* the enemy loses a health. If 3 hits, the enemy dies and gives points to the player.
*/
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
private:
		int health;			//Current health of the enemy.
	  double speed;			//travel speed of the enemy.
	  double shootSpeed;	//how fast the bullets move when spawned.
	  int numberOfBullets; // how many bullets enemy can spawn.
		
		//Animation
		int animationSpeed;	//speed of animation
		int animationFrame;	//current animation frame.
		int animationCounter;	//A timer for the animation to change frames
		int RanimationCounter; //The reset timer for how quickly animations change from frame to frame.
		MyList<QPixmap*>* anim;	//A MyList list of QPixmap pointers for the animation.
		
		int spawnBulletCounter;	//A timer for how quickly an enemy can spawn bullets.
		int RspawnBulletCounter;	//The reset timer for how quickly players can spawn bullets.
		
		int moveToPositionX; //The position X the enemy should move to.
		int moveToPositionY; // The Y position the enemy should move to.
		
		Player* playerRef;	//A reference to the player to add score to the main game when the player kills an enemy.
		
};

#endif 
