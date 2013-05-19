/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "Enemy.h"
	
/**Enemy constructor that constructs an enemy with x,y coordinates and z depth with a given picture and/or animation)
* Tag: "Enemy"
* @param nx Spawn X location of Health (+X is rightwards)
* @param ny Spawn Y location of Health (+Y is downwards)(
* @param nz Spawn Depth location of Health (+Z is more front)
* @param pixmap The sprite Health Box will display.
* @param animation A MyList of animations sprites.
* @param moveToX The X direction the enemy will move towards.
* @param moveToY The Y direction the enemy will move towards.
* @param speed The speed at which the enemy will travel.
* @param shootSpeed The speed at which the enemy's bullets will travel.
*/
Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed, double shootSpeed): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	anim = animation;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	type = "Enemy";
	
	this->speed = speed;
	this->shootSpeed=shootSpeed;
	
	numberOfBullets=1;
	
	//Counters
	animationCounter=0;
		RanimationCounter=70;
	spawnBulletCounter=800;
		RspawnBulletCounter=800;
		
		setTransformOriginPoint(0,0);
		
	health = 3;
}
/**Enemy constructor that constructs an enemy with x,y coordinates and z depth with a given picture no animation)
* Tag: "Enemy"
* @param nx Spawn X location of Health (+X is rightwards)
* @param ny Spawn Y location of Health (+Y is downwards)(
* @param nz Spawn Depth location of Health (+Z is more front)
* @param pixmap The sprite Health Box will display.
* @param moveToX The X direction the enemy will move towards.
* @param moveToY The Y direction the enemy will move towards.
* @param speed The speed at which the enemy will travel.
* @param shootSpeed The speed at which the enemy's bullets will travel.
*/
Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed, double shootSpeed):GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;

	anim=NULL;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	type = "Enemy";
	
	this->speed = speed;
	this->shootSpeed=shootSpeed;
	
	
	//Counters
	animationCounter=0;
		RanimationCounter=70;
	spawnBulletCounter=800;
		RspawnBulletCounter=800;
		
		setTransformOriginPoint(0,0);
		
	health = 3;
}
	
Enemy::~Enemy(){

}

/** Collision function is called every millisecond. Handles the collision between Enemy and player bullets. If a player bullet hits the enemy,
* the enemy loses a health. If 3 hits, the enemy dies and gives points to the player.
* @param gameObjects A MyList of the game objects in the scene. Used to loop through for collision detection.
*/
void Enemy::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	//Loop through game objects
	for (int i=0; i<gameObjects->size(); i++){
		//If a player missile found
		if (gameObjects->at(i)->getType() == "PlayerMissile"){
			//if missile collided with enemy
			if (collidesWithItem(gameObjects->at(i))){
				//destroy the missile
				gameObjects->at(i)->HandleCollision(type);
				//Hurt enemy
				setHealth(getHealth()-1);
					//if enemy health less than 0
				if (health<=0){
					//Implement dying here later.
					//give a player +25 score
					emit addScore(25);
					//destroy enemy
					emit Destroy(this);
					return;
				}
			}
		}
	}
}

/**Update function is called every millisecond. Handles the animation of the enemy if there is one and the movement from left to right
* or right to left depending on where the enemy spawns. Also destroys the enemy if the enemy goes offscreen.
*/
void Enemy::Update(){

//if enemy goes offscreen. destroy the enemy
if (gX()>680 || gX()<-100){
	emit Destroy(this);
	return;
}

//Animate the enemy if there is an animation
	if (anim!=NULL){
		if (animationCounter<=0){
			animationCounter=RanimationCounter;
			if (animationFrame<anim->size()){
				setPixmap(*(anim->at(animationFrame)));
			}
			else{
				animationFrame=-1;
			}	
			animationFrame++;
		}
		if (animationCounter>0){
			animationCounter--;
		}
	}
//------------------------

	//Shoot bullets
	if (spawnBulletCounter<=0){
		spawnBulletCounter = RspawnBulletCounter;
		//Make a new bullet.
		if (isFlipped()){
			for (int i=0; i<numberOfBullets; i++){
				//spawn bullets based on how many bullets can be spawned.
				emit Spawn(0, gX()-40, gY()+30, shootSpeed);
			}
		}
		else {
			for (int i=0; i<numberOfBullets; i++){
				//spawn bullets based on how many bullets can be spawned.
				emit Spawn(0,gX()+20, gY()+30, shootSpeed);
				}
		}
	}
	if(spawnBulletCounter>0){
		spawnBulletCounter--; // counter for bullet spawning.
	}

	// Move in a set direction.
	MoveDir(moveToPositionX,moveToPositionY,speed);
}
	/**Gives the Enemy a reference to the player to add score when the enemy is destroyed
	* @param player The main player in the game.
	*/
void Enemy::setPlayerRef(Player* player){
	playerRef = player;
}
/** Health of the enemy.
* @return Returns the health of the enemy.
*/
int Enemy::getHealth(){
	return health;
}
/** Sets the health of the enemy.
* @param health the new health of the enemy.
*/
void Enemy::setHealth(int health){
	this->health = health;
}
/**Sets the number of bullets an enemy can spawn at any given time. The game increments the number of bullets every 15 seconds
* @param num Number of bullets that can be spawned at a given shot.
*/
void Enemy::setNumOfBullets(int num){
	numberOfBullets=num;
}
	/**Sets the rate at which the enemy can fire his bullets.
	* @param num Rate of fire in milliseconds.
	*/
void Enemy::setRSpawnBulletCounter(int num){
	RspawnBulletCounter = num;
}












