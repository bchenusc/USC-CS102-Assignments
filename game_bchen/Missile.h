/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef MISSILE
#define MISSILE
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <string>

class Missile : public GameObject {
	
public:
	Missile(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed);
	~Missile();
	void HandleCollision(string type);
	
public slots:
	virtual void Update();
	
private:
		void explosion(); //Destroys Missile.
	  double speed;
		//Animation Variables
		int animationSpeed;
		int animationFrame;
		int animationCounter;
		int RanimationCounter;
		MyList<QPixmap*>* anim;
		
		int moveToPositionX;
		int moveToPositionY;
		
};
#endif
