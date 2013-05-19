/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "Turret.h"
	
/**Constructor. Creates a Turret  at a given x, y position with z depth and a given QPixmap.
* Turret travels at a speed given by the last parameter of the constructor.
* Tag: "Turret"
* @param nx Spawn X location of Turret (+X is rightwards)
* @param ny Spawn Y location of Turret (+Y is downwards)(
* @param nz Spawn Depth location of Turret (+Z is more front)
* @param pixmap The sprite Turret will display.
* @param player The player that the turret will follow.
*/
Turret::Turret(int nx, int ny, int nz, QPixmap* pixmap, Player* player): GameObject( nx,  ny, nz, pixmap){
	type="Turret";
	this->player = player;
	flipImg(true);
	setTransformOriginPoint(18,59);
	shootSpeed=0.5;
	
	//Cooldown timers
	shootCounter =0;
	RshootCounter = 100;
}
/**Default destructor*/
Turret::~Turret(){

}
/**Sets an offset for the Turret's position relative to the player's position
*	@param nx The x offset.
*/
void Turret::setLockX(int nx){
	lockX=nx;
}
/**Sets an offset for the Turret's position relative to the player's position
*	@param ny The y offset.
*/
void Turret::setLockY(int ny){
	lockY=ny;
}
/** Sets the rate of fire of the turret.
*	@param shoot The new rate of fire.
*/
void Turret::setRShootCounter(int shoot){
	RshootCounter = shoot;
}
/** Gets the rate of fire of the turret.
* @return Returns the rate of fire of the turret.
*/
int Turret::getRShootCounter(){
	return RshootCounter;
}
/** Handles when the mouse is pressed in the view.
* The Turret will Spawn a bullet at the base of the turret behind the turret.
* @param mx The x location of the mouse.
* @param my The y location of the mouse.
*/
void Turret::mousePressed(int mx, int my){
	if (shootCounter==0){
		shootCounter=RshootCounter;
		//if statement determines where the mouse is relative to the player. This determines which direction the bullet should travel.
		if ((mx>player->gX() && my >=player->gY()-10) || (mx<player->gX() && my>=player->gY()-10)){
			//Everytime you shoot you lose 5 points.
			emit addScore(-5);
			//Spawns a bullet
			emit Spawn(2, mx, my, shootSpeed*2);
			return;
			}
		else{
		//everytime you shoot you lose 5 points
			emit addScore(-5);
			//Spawns a bullet.
			emit Spawn(2,mx, my, -shootSpeed*2);
		return;
		}
	}
}

/** Handles the turret looking at the mouse's x and y position.
*	@param mx The mouse X position.
* @param my The mouse Y position.
*/
void Turret::mouseFollow(int mx, int my){
	int mouseX = mx;
	int mouseY = my;
	double pi = 3.14159;
	double theta=rotation();

//Calculate the angle made by the player's x-axis using pythagorean theorem.
	if (mouseX > player->gX() && mouseY<player->gY()){
		theta = acos((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))+pi;
	}
	else
	if (mouseX>player->gX() && mouseY>player->gY())theta =-asin((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))-pi/2;
	else 
		theta = -acos((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))+pi;

//Rotating the turret using the angle made by the player's x-axis.
	setRotation(theta*180/pi);
}

/** Update called every millisecond. Handles the Turret being parented to the mainPlayer.
*/
void Turret::Update(){
	//Follow the player
	setPos(player->gX()+lockX, lockY);
	x = player->gX()+lockX;
	y=player->gY()+lockY;
	
	//Resets the shoot timer allowing for multiple shots.
	if(shootCounter>0){
		shootCounter--;
	}
}







