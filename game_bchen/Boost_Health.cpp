/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "Boost_Health.h"

/**Constructor. Creates a health box at a given x, y position with z depth and a given QPixmap.
* Health box travels at a speed given by the last parameter of the constructor.
* Tag: "HealthBoost"
* @param nx Spawn X location of Health (+X is rightwards)
* @param ny Spawn Y location of Health (+Y is downwards)(
* @param nz Spawn Depth location of Health (+Z is more front)
* @param pixmap The sprite Health Box will display.
* @param speed The speed the Health Box travels.
*/
Boost_Health::Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	initialX = nx;
	initialY = ny;
	type = "HealthBoost";
	isMovingLeft = true;
	setTransformOriginPoint(0,0);
	this->speed = speed;
}
/**Default destructor*/
Boost_Health::~Boost_Health(){

}
/**	Sets a reference to the player. Boost_Health needs this reference to edit the player's health.*/
void Boost_Health::setPlayerRef(Player *player){
	playerRef = player;
}

/** Called every millisecond. Handles collision with player and/or player bullets. Adds 1 to the health of Player.*/
void Boost_Health::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	//Loop through all game objects in the scene.
	for (int i=0; i<gameObjects->size(); i++){
			//check the tag of the gameobject. if it's PlayerMissile or Player and collides with this object  then add 1 to the health.
			if (gameObjects->at(i)->getType() == "PlayerMissile" || gameObjects->at(i)->getType() == "Player"){
				if (collidesWithItem(gameObjects->at(i))){
					//Make the other thing that collides with you handle its own collision. ex. Missiles will just destroy themselves.
					gameObjects->at(i)->HandleCollision(type);
					//Add one to the player.
					playerRef->setHealth(playerRef->getHealth()+1);
					//change the health bar GUI.
					emit changeHealth(playerRef->getHealth());
					//Destroy the health box.
					emit Destroy(this);
					return;
				}
			}
			
		}
}

/** Called every millisecond. Handles oscillation movement and destroys health box if it hits the ground.*/
void Boost_Health::Update(){
// If th box ever goes into some weird boundaries.
	if (gX()>680 || gX()<-100){
		emit Destroy(this);
		return;
	}
//------------------------
//Health oscillates horizontally moving between + or - 150 from its original location.
//disappears if the health touches the ground.	
	if (isMovingLeft && (gX()<=initialX-150 ||gX()<=5)){
	//Too Far left
		isMovingLeft = false;
		MoveDir(1,-1, speed);
	}else
	if (!isMovingLeft && (gX()>=initialX+150 || gX()>=450)){
	//Too far right
		isMovingLeft = true;
		MoveDir(-1,-1,speed);
	}else
	if (isMovingLeft && gX()>initialX-150){
	//Moving Left
		MoveDir(1,-1, speed);
	}else
	if (!isMovingLeft && gX()<initialX+150){
	//Moving Right
		MoveDir(-1,-1,speed);
	}
	//If hit the ground then destroy.
	if (gY()>=400)
	{
		Destroy(this);
		return;
	}
}













