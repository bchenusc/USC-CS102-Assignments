/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "Player.h"

/**Constructor. Creates a Player  at a given x, y position with z depth and a given QPixmap.
* Player travels at a speed given by the last parameter of the constructor.
* Tag: "Player"
* @param nx Spawn X location of Player (+X is rightwards)
* @param ny Spawn Y location of Player (+Y is downwards)(
* @param nz Spawn Depth location of Player (+Z is more front)
* @param pixmap The sprite Player will display.
* @param animation The animation MyList of QPixmap pointers that will animate the character.
*/
Player::Player(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=32;
	anim = animation;
	animationFrame=0;
	type="Player";
	moveSpeed=4;
	health=3;
	setTransformOriginPoint(pixmap->width()/2, pixmap->height()/2);
	moving=0;
	playerDead=false;
}
	/** Default destructor*/
Player::~Player(){

}
/**Spawns a turret right behidn the player.*/
void Player::spawnTurret(){
	//Spawn a turret on the player.
	emit Spawn(1, gX()-60, gY()-50, 0);
	return;
}
/**Handles the keypressed event sent from the main window. if A or D are pressed then move left or right respectively.
*	@param key The information sent by QKeyEvent that stores the key that is pressed. Only one key can be pressed at a time.
*/
void Player::keyPressed(QKeyEvent* key){
	if (key->key() == Qt::Key_A){
		if (gX()>5)
			moving=1;
	}else
	if (key->key() == Qt::Key_D){
		if (gX()<600)
			moving=2;
	}
}

void Player::keyReleased(QKeyEvent* key){
	moving=0;
}

/**Update is called every millisecond. Handles the player animation*/
void Player::Update(){

	if (moving==1){
		if (gX()>5)
		MoveDir(-1,  0,  moveSpeed/10.0);
	}else
	if (moving==2){
		if (gX()<600)
		MoveDir(1,  0,  moveSpeed/10.0);
	}



//Animate the player
	if (animationCounter<=0){
		animationCounter=RanimationCounter;
		if (animationFrame<anim->size()){
			//changes the player animation frame.
			setPixmap(*(anim->at(animationFrame)));
		}
		else{
			//Loops the animation frame.
			animationFrame=-1;
		}	
		animationFrame++;
	}
	if (animationCounter>0){
		animationCounter--;
	}
}

/**Collision function called every millisecond. Loops through all the game objects in the scene and checks whether they are of 
* "EnemyMissile" or "EnemyHamster" type. If they are, then decrease the health of the player.
* @param gameObjects A MyList of all the game objects in the scene.
*/
void Player::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	if (playerDead){return;}
	for (int i=0; i<gameObjects->size(); i++){
		if (playerDead){return;}
		if (gameObjects->at(i)->getType() == "EnemyMissile" || gameObjects->at(i)->getType() == "EnemyHamster"){
			if (playerDead){return;}
			if (collidesWithItem(gameObjects->at(i))){
				gameObjects->at(i)->HandleCollision(type);
				setHealth(getHealth()-1);
				emit changeHealth(getHealth());
				if (health<=0){
					if (playerDead){return;}
				//Implement dying here later.
					emit Lose();
					playerDead=true;
					return;
				}
			}
		}
	}
}

/**Sets the move speed of the player
*	@param speed The movement speed of the Player.
*/
void Player::setMoveSpeed(int speed){
	moveSpeed=  speed;
}

/** Returns the movement speed of the player
* @return Returns the movement speed of the player.
*/
int Player::getMoveSpeed(){
	return moveSpeed;
}

/** Gets the player's health
*	@return Returns the player's health
*/
int Player::getHealth(){
	return health;
}
/** Sets the health of the player
*	@param health Sets the health of the player.
*/
void Player::setHealth(int health){
	if (health<=3)
		this->health = health;
	else 
	this->health = 3;
}
