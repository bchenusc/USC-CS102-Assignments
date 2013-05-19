/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "ExtraPoints.h"

/**Constructor. Creates a point box at a given x, y position with z depth and a given QPixmap.
* Health box travels at a speed given by the last parameter of the constructor.
* Tag: "PointBoost"
* @param nx Spawn X location of Health (+X is rightwards)
* @param ny Spawn Y location of Health (+Y is downwards)(
* @param nz Spawn Depth location of Health (+Z is more front)
* @param pixmap The sprite Health Box will display.
* @param speed The speed the Health Box travels.
*/
ExtraPoints::ExtraPoints(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	initialX = nx;
	initialY = ny;
	type = "PointBoost";
	setTransformOriginPoint(0,0);
	this->speed = speed;
}
/**Default destructor*/
ExtraPoints::~ExtraPoints(){

}
/**	Sets a reference to the player. Boost_Health needs this reference to edit the player's health.*/
void ExtraPoints::setPlayerRef(Player *player){
	playerRef = player;
}

/** Called every millisecond. Handles collision with player and/or player bullets. Adds 1 to the health of Player.*/
void ExtraPoints::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	//Loop through all game objects in the scene.
	for (int i=0; i<gameObjects->size(); i++){
			//check the tag of the gameobject. if it's PlayerMissile or Player and collides with this object  then add 1 to the health.
			if (gameObjects->at(i)->getType() == "PlayerMissile" || gameObjects->at(i)->getType() == "Player"){
				if (collidesWithItem(gameObjects->at(i))){
					//Make the other thing that collides with you handle its own collision. ex. Missiles will just destroy themselves.
					gameObjects->at(i)->HandleCollision(type);
					//change the health bar GUI.
					emit addScore(100);
					//Destroy the health box.
					emit Destroy(this);
					return;
				}
			}
			
		}
}

/** Called every millisecond. ExtraPoints follows player.*/
void ExtraPoints::Update(){
// If th box ever goes into some weird boundaries.
	if (gX()>680 || gX()<-100){
		emit Destroy(this);
		return;
	}
//------------------------
// Goes towards the player.
	MoveDir(playerRef->gX() - gX()+10, playerRef->gY() - gY()+20, speed);

	//If hit the ground then destroy.
	if (gY()>=400)
	{
		Destroy(this);
		return;
	}
}













