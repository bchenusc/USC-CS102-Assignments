#include "guitile.h"
#include <QGraphicsSimpleTextItem>
#include <cmath>
#include <iostream>

/** This function checks if the parameter s is a valid integer.
* @param nx The X location of the gui tile.
* @param ny The Y location of the gui tile.
* @param w The width of the gui tile.
* @param h The height of the gui tile.
* @param val the value of the tile.
* @return Boolean value that returns true if the string s is a valid integer and false if it is not.
*/
GUITile::GUITile(double nx, double ny, double w, double h,int val) :
    QGraphicsRectItem(nx, ny, w, h) {
    //Converts the number to a Qstring to be displayed on the tile.
    if (val!=0){
		  QString number = QString::number(val);
		  gfxTile = new QGraphicsSimpleTextItem(number, this);
    }
    else gfxTile = new QGraphicsSimpleTextItem("",this);
    //Sets the display of the number on the correct spot on the tile.
	  gfxTile->setX(nx-((int)(log10(val))+1)*4+w/2);
	  gfxTile->setY(ny-7+h/2);
	  //Sets the x and y values of the tile and width and height and value.
	  x = nx;
	  y = ny;
	  width = w;
	  height = h;
	  this->val = val;
	  //creates a timer for each tile.
    timer = new QTimer(this);
    //Tile is not moving.
    isMoving = false;
    timer->setInterval(5);
    if (val==0){
    //Deletes the border of the blank tile.
    	setPen(Qt::NoPen);
    }
}

/** Getter that gets the value of the tile.
* @return Returns the value of the tile as an integer.
*/
int GUITile::getVal(){
	return val;
}
/** Gets the X coordinate of the tile.
* @return Returns the x coord of the tile as an integer.
*/
int GUITile::getX() {
    return x;
}
/** Gets the Y coordinate of the tile.
* @return Returns the y coord of the tile as an integer.
*/
int GUITile::getY() {
    return y;
}
/** Sets the graphic tile's # to the character parameter s.
* @param s sets the tile's character.
*/
void GUITile::setText(char s){
	QString qstr (s);
	gfxTile->setText(qstr);
}
/** Sets the X coordinate of the tile to the parameter nx.
* @param nx the new x coordinate that the tile should be set to.
*/
void GUITile::setX(int nx) {
    x = nx;
}
/** Sets the Y coordinate of the tile to the parameter ny.
* @param nx the new y coordinate that the tile should be set to.
*/
void GUITile::setY(int ny) {
    y = ny;
}
/** Sets the X coordinate of the target that the tile is moving to.
* @param x changes the moveTargetX. The tile will move to this location.
*/
void GUITile::setTargetX(int x){
	moveTargetX = x;
}
/** Sets the Y coordinate of the target that the tile is moving to.
* @param y changes the moveTargetY. The tile will move to this location.
*/
void GUITile::setTargetY(int y){
	moveTargetY = y;
}
/** Moves the tile to the specified location.
* @param nx The x position of where the tile should move to.
* @param ny The y position of where the tile should move to.
*/
void GUITile::moveTile(int nx, int ny){
	if (!isMoving){
		moveTargetX=nx;
    moveTargetY=ny;          
		
		timer->start();
		isMoving=true;
	}
}
/** Creates the animation of the tile using a timer. Moves the tile to the moveTargetX and moveTargetY
* that the tile stores.
*/
void GUITile::handleTimer(){
		int vx, vy;
		//check where the tile is
		//is the target tile on the left
		if (x>moveTargetX){
			vx = -1;
			vy= 0;
		}else
		//is the target tile on the right
		if (x<moveTargetX){
			vx = 1;
			vy= 0;		
		}else
		//is the target tile on below?
		if (y>moveTargetY){
			vx = 0;
			vy= -1;			
		}else
		//is the target tile above?
		if (y<moveTargetY){
			vx = 0;
			vy= 1;			
		}else
		{
			timer->stop();
			isMoving=false;
			emit toggleTileInGridIsMoving(false);
			return;
		}
		
		x+=vx;
		y+=vy;
		//Moves the tile to the x and y position.
		QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect(r);
    //Moves the label for the value along with the tile.
    gfxTile->setX(x-((int)(log10(val))+1)*4+width/2);
    gfxTile->setY(y-7+height/2);
}
/** An event that is triggered whenever the mouse clicks a tile. Emits a mouseIsPressed(int) signal.
*/
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent * event){
	if (!isMoving){
	QGraphicsItem::mousePressEvent(event);

	emit mouseIsPressed(val);
	}	
}


