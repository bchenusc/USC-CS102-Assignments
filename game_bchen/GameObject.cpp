/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "GameObject.h"

/** Constructs a GameObject with x,y location; z depth and a picture. Calls the QGraphicsPixmapItem to create the picture.
* Health box travels at a speed given by the last parameter of the constructor.
* @param nx Spawn X location of Health (+X is rightwards)
* @param ny Spawn Y location of Health (+Y is downwards)(
* @param nz Spawn Depth location of Health (+Z is more front)
* @param pixmap The sprite Health Box will display.
*/
GameObject::GameObject(int nx, int ny,int nz, QPixmap* pixmap): QGraphicsPixmapItem(*pixmap){
	  x = nx;
    y = ny;
    setPos(x,y);
    setZValue(nz);
    vx=0;
    vy=0;
    this->pixmap = pixmap;
    dirX=0;
    dirY=0;
}
/** Default destructor*/
GameObject::~GameObject(){
	
}
/**Gets the X location of the GameObject*/
int GameObject::gX(){
		return x;
}
/**Gets the Y location of the GameObject*/
int GameObject::gY(){
	return y;
}
/*Tells whether GameObject is flipped around its transform point or not.*/
bool GameObject:: isFlipped(){
	return flipHorizontal;
}
/**Collision detection must be implemented in each subclass. Called every millisecond. No implementation for GameObjects class.*/
void GameObject::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	objects=gameObjects;
}

/**Flips the image based on whether the parameter is true or false. Uses a transformation matrix to flip the image.*/
void GameObject:: flipImg(bool flip){
	if (flip==true){
		flipHorizontal=true;
		//Creating a transformation matrix. Yay linear algebra.
		QTransform transform(this->transform());
	
		transform.setMatrix(-transform.m11(), transform.m12(),transform.m13(),transform.m21(),transform.m22(),transform.m23(),transform.m31(),transform.m32(),transform.m33());
		setTransform(transform);
		setTransformOriginPoint(-80,0);
	}
	else
		flipHorizontal=false;
		//Creating a transformation matrix. Yay linear algebra.
		QTransform transform(this->transform());
	
		transform.setMatrix(transform.m11(), transform.m12(),transform.m13(),transform.m21(),transform.m22(),transform.m23(),transform.m31(),transform.m32(),transform.m33());
		setTransform(transform);
		setTransformOriginPoint(0,0);
}
/**Moves the GameObject towards a location with a given speed
* @param x X Position to move towards
* @param y Y Position to move Towards
* @param speed The speed to move towards x,y location
*/
void GameObject:: MoveTowards(double x, double y, double speed){
	//Find the Vector2 direction.
	int deltaX = x-gX();
	int deltaY = y-gY();
	
	double pi = 3.14159;
	
	double theta=0;
	
	if (deltaY!=0)
		theta = atan(deltaX/(double)deltaY)*180/pi;
	
	double vX = sin(theta*pi/180)*speed;
	double vY = cos(theta*pi/180)*speed;
	
	if (deltaY==0){
		vY = 0;
		vX = speed;
	}
	
	if (abs(deltaX)<=1){
		vX=0;
		vY=speed;
	}
	if (abs(deltaY)<=1){
		vX=speed;
		vY=0;
	}

	setPos(gX()+vX, gY()+vY);
//moveBy(vX, vY);
	this->x = QGraphicsItem::x();
	this->y = QGraphicsItem::y();

}
/**The tag of the game object. Each class has a different tag
* @return Returns the type of this game object.
*/
string GameObject::getType(){
	return type;
}
/**Not all classes need this implemented. Normally used if something else collides with the game object.
* @param type The tag of the object that collided with this game object.
*/
void GameObject::HandleCollision(string type){
	this->type = type;
}
/**sets the tag of the game object
* @param nType The new tag for the object.
*/
void GameObject::setType(string nType){
	type = nType;
}
/** Moves in the direction of deltax and deltay at a given speed
* @param deltaX The X direction to move towards.
* @param deltaY The Y direction to move towards.
* @param speed The speed at which the game object moves towards x and y.
*/
void GameObject:: MoveDir(double deltaX, double deltaY, double speed){

	double pi = 3.14159;
	double theta = atan(deltaX/(double)deltaY)*180/pi;
	
	 vx = sin(theta/180*pi)*speed;
	 vy = cos(theta/180*pi)*speed;
	
	if (deltaX==0 && deltaY!=0 && deltaY>0){
		vx=0;
		vy=speed;
		moveBy(0, speed);
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaX==0 && deltaY!=0 && deltaY<0){
		vx=0;
		vy=-speed;
		moveBy(0, -speed);
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX!=0 && deltaX>0){
		vx = speed;
		vy=0;
		moveBy(speed, 0);
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX!=0 && deltaX<0){
		vx= -speed;
		vy=0;
		moveBy(-speed, 0);
		this->x=QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX==0){
		vx=0;
		vy=0;
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	
	moveBy(vx, vy);
	this->x = QGraphicsItem::x();
	this->y = QGraphicsItem::y();

	
}

//SLOTS
/** Empty update class. If a subclass does not have an update class, it will inherit it from GameObject and simply do nothing in the update.*/
void GameObject:: Update(){

}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
