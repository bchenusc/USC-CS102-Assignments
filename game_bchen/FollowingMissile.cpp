/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "FollowingMissile.h"

/**Constructor. Creates a FollowMissile at a given x, y position with z depth and a given QPixmap.
* Health box travels at a speed given by the last parameter of the constructor.
* Tag: "PointBoost"
* @param nx Spawn X location of Health (+X is rightwards)
* @param ny Spawn Y location of Health (+Y is downwards)(
* @param nz Spawn Depth location of Health (+Z is more front)
* @param pixmap The sprite Health Box will display.
* @param player The player pointer. Used to get its initial position at the creation of the missile.
* @param speed The speed the Health Box travels.
*/
FollowMissile::FollowMissile(int nx, int ny, int nz, QPixmap* pixmap, Player* player, double speed):GameObject( nx,  ny, nz, pixmap){
	initialGoToX = player->gX();
	initialGoToY = player->gY();
	initialX = nx;
	initialY = ny;
	type = "EnemyMissile";
	setTransformOriginPoint(0,0);
	this->speed = speed;
}
/**Default destructor*/
FollowMissile::~FollowMissile(){

}

/**If another object calls this function, then the Missile will destroy itself depending on what the type of the object that is calling.
*	Cases "Player" type hits this Missile and Missile is of "EnemyMissile"
*	Cases "Enemy" type hits this Missile and Missile is of "PlayerMissile"
*	Cases "HealthBoost" type hits this Missile and Missile is of "PlayerMissile"
*	Cases "ENemyHamster" type hits this Missile and Missile is of "PlayerMissile"
* @param type The tag that hit this missile.
*/
void FollowMissile::HandleCollision(string type){
	//Explosion here if needed.
	//Checks what type
	if (this->type == "EnemyMissile" && type=="Player"){
		emit Destroy(this);
		return;
	}
	else if (this->type == "PlayerMissile" && type=="Enemy"){
		emit Destroy(this);
		return;
	}
	else if (this->type == "PlayerMissile" && type == "HealthBoost"){
		emit Destroy(this);
		return;
	}
	else if (this->type == "PlayerMissile" && type == "EnemyHamster"){
		emit Destroy(this);
		return;
	}
}

/** Called every millisecond. Goes to the player's initial position.*/
void FollowMissile::Update(){
// If th box ever goes into some weird boundaries.
	if (gX()>680 || gX()<-100){
		emit Destroy(this);
		return;
	}
//------------------------
// Goes towards the player.
	MoveDir(initialGoToX - initialX , initialGoToY - initialY, 0.9);

	//If hit the ground then destroy.
	if (gY()>=375)
	{
		Destroy(this);
		return;
	}
}













