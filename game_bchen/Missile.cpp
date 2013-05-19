/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "Missile.h"
	
/**Constructor. Creates a Missile  at a given x, y position with z depth and a given QPixmap.
* Missile travels at a speed given by the last parameter of the constructor.
* Tag: "Missile"
* @param nx Spawn X location of Missile (+X is rightwards)
* @param ny Spawn Y location of Missile (+Y is downwards)(
* @param nz Spawn Depth location of Missile (+Z is more front)
* @param pixmap The sprite Missile will display.
* @param moveToY Y position missile should move towards.
* @param moveToX x positon missile should move towards.
* @param speed The speed the Missile travels.
*/
Missile::Missile(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed):GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=70;
	anim=NULL;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	this->speed=speed;
	type="Missile";
	setRotation(-90);
}
/** Default destructor */
Missile::~Missile(){

}
/**If another object calls this function, then the Missile will destroy itself depending on what the type of the object that is calling.
*	Cases "Player" type hits this Missile and Missile is of "EnemyMissile"
*	Cases "Enemy" type hits this Missile and Missile is of "PlayerMissile"
*	Cases "HealthBoost" type hits this Missile and Missile is of "PlayerMissile"
*	Cases "ENemyHamster" type hits this Missile and Missile is of "PlayerMissile"
* @param type The tag that hit this missile.
*/
void Missile::HandleCollision(string type){
	//Explosion here if needed.
	//Checks what type
	if (this->type == "EnemyMissile" && type=="Player"){
		explosion();
		return;
	}
	else if (this->type == "PlayerMissile" && type=="Enemy"){
		explosion();
		return;
	}
	else if (this->type == "PlayerMissile" && type == "HealthBoost"){
		explosion();
		return;
	}
	else if (this->type == "PlayerMissile" && type == "EnemyHamster"){
		explosion();
		return;
	}
}

/**Just deletes this missile from the scene.*/
void Missile::explosion(){
	emit Destroy(this);
	return;
}
/**Update function called every millisecond.
* If missile outside of screen then destroy itself.
* Moves the missile towards its target location given by moveToTargetX, moveToTargetY.
*/
void Missile::Update(){

//If out of bounds of the screen then destroy the missile.
	if (gX()<= -1000 || gX()>=1500|| gY()<= -1000 || gY()>=1000){
			emit Destroy(this);
			return;
	}

	//Tweek this to set a different location where the missile explodes when hitting the ground.
	if (gY()>=400){
		emit Destroy(this);
		return;
	}
	else{
	
//Animate the misssile if ther is an animation given.
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
	}

	//move missile towards target location most probably the player.
	MoveDir(moveToPositionX,moveToPositionY,speed);

}






















