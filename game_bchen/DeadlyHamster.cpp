/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "DeadlyHamster.h"
	
/**Constructor. DeadlyHamster constructor. Creates a Hamster that moves left along the ground.
* Calls the GameObject constructor to create the sprite.
* Tag: "EnemyHamster"
* @param nx Spawn X location of Hamster (+X is rightwards)
* @param ny Spawn Y location of Hamster (+Y is downwards)(
* @param nz Spawn Depth location of Hamster (+Z is more front)
* @param pixmap The sprite Hamster will display.
* @param speed The speed the Hamster travels.
*/
DeadlyHamster::DeadlyHamster(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	type = "EnemyHamster";
	this->speed = speed;
	setTransformOriginPoint(0,0); //Set transformation point.
}
/**Default destructor*/
DeadlyHamster::~DeadlyHamster(){

}
/**If collides with a "Player" type object, then the Hamster will destroy itself and add dammage to the player.
* @param type The tag of the object colliding with the DeadlyHamster.
*/
void DeadlyHamster::HandleCollision(string type){
	if (type == "Player"){
		Destroy(this);
		return;
	}
}
/**Collision is called every millisecond. Handles the collision of the hamster with the Player's missile.
* If missile hits hamster, hamster dies and gives player 10 points.
* @param gameObjects A MyList that points to the current game objects in the scene.
*/
void DeadlyHamster::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	//Loop through all game objects.
	for (int i=0; i<gameObjects->size(); i++){
		//Determine if gameObject is of type "PlayerMissile"
		if (gameObjects->at(i)->getType() == "PlayerMissile"){
			//Determine if you collide with that "PlayerMissile"
			if (collidesWithItem(gameObjects->at(i))){
					//Make the player missile disappear.
					gameObjects->at(i)->HandleCollision(type);
					//Add to your game score +10
					emit addScore(10);
					//Destroy self (Hamster)
					emit Destroy(this);
					return;
				}
			}
		}
}

/** Update is called every millisecond. 
* Moves the hamster to the left. Destroys the Hamster if it goes off the screen.
*/
void DeadlyHamster::Update(){

if (gX()>680 || gX()<-100){
	emit Destroy(this);
	return;
}

	// Move in a set direction.
	MoveDir(-1,0,speed);
}










