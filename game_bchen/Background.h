/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef BACKGROUND
#define BACKGROUND
#include <QGraphicsPixmapItem>
#include "GameObject.h"

/**
	 Scrollable Background class. Scrolls to the right with a given speed.
*/
class Background : public GameObject {
	
public:
	/*Background constructor. Creates a background.*/
	Background(int nx, int ny, int nz, QPixmap* pixmap); 
	/*Background destructor*/
	~Background();
	/*Sets the speed of the scrolling background.*/
	void setSpeed(int i);
	
public slots:
	/*Update function called every millisecond to handle movement.*/
	void Update();

private:
	int speed;	//speed of the background.
	
};

#endif 
