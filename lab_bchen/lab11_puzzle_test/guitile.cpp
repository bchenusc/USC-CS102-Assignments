#include "guitile.h"
#include <QGraphicsSimpleTextItem>
#include <cmath>

#include <iostream>

GUITile::GUITile(double nx, double ny, double w, double h,int val) :
    QGraphicsRectItem(nx, ny, w, h) {
    if (val!=0){
    QString number = QString::number(val);
    gfxTile = new QGraphicsSimpleTextItem(number, this);
    }
    else gfxTile = new QGraphicsSimpleTextItem("",this);
    gfxTile->setX(nx-((int)(log10(val))+1)*4+w/2);
    gfxTile->setY(ny-7+h/2);
    x = nx;
    y = ny;
    width = w;
    height = h;
    this->val = val;
    timer = new QTimer(this);
    isMoving = false;
    timer->setInterval(5);
    if (val==0){
    	setPen(Qt::NoPen);
    }
}

int GUITile::getVal(){
	return val;
}

int GUITile::getX() {
    return x;
}

int GUITile::getY() {
    return y;
}

void GUITile::setText(char s){
	QString qstr (s);
	gfxTile->setText(qstr);
}

void GUITile::setX(int nx) {
    x = nx;
}

void GUITile::setY(int ny) {
    y = ny;
}
void GUITile::setTargetX(int x){
	moveTargetX = x;
}
void GUITile::setTargetY(int y){
	moveTargetY = y;
}
void GUITile::moveTile(int nx, int ny){
	if (!isMoving){
		moveTargetX=nx;
    moveTargetY=ny;          
		
		timer->start();
		isMoving=true;
	}
}

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

		QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect(r);
    
    gfxTile->setX(x-((int)(log10(val))+1)*4+width/2);
    gfxTile->setY(y-7+height/2);
}

void GUITile::mousePressEvent(QGraphicsSceneMouseEvent * event){
	if (!isMoving){
	QGraphicsItem::mousePressEvent(event);

	emit mouseIsPressed(val);
	}	
}


