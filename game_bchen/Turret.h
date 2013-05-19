/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef TURRET
#define TURRET
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include "Player.h"

class Turret :  public GameObject {
	Q_OBJECT
		
public:
	explicit Turret(int nx, int ny,int nz, QPixmap* pixmap, Player* player);
	~Turret();
	void setLockX(int nx);
	void setLockY(int ny);
	void mouseFollow(int mx, int my);
	void setRShootCounter(int shoot);
	int getRShootCounter();
	void mousePressed(int x, int y);
	
signals:
/**Adds a score (int) to the player's score*/
	void addScore(int);
	
	
public slots:
	void Update();
	
private:
	Player* player;
	double shootSpeed;
	int lockX;
	int lockY;
	
	//Cooldown timers
	int shootCounter;
	int RshootCounter;
};

#endif 
