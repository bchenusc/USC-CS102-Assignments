/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <QGraphicsPixmapItem>
#include <math.h>
#include <string>
#include "mylist.h"

class GameObject : public QObject, public QGraphicsPixmapItem {

	Q_OBJECT
	
public:
 
	explicit GameObject(int nx, int ny, int nz, QPixmap* pixmap);
	~GameObject();
	int gX();
	int gY();
	void setType(string type);
	string getType();
	bool isFlipped();
	void flipImg(bool flip);
	void MoveTowards(double x, double y, double speed);
	void MoveDir(double x, double y, double speed);
	
	virtual void HandleCollision(string type);
	
	
signals:
/**Destroy signal that links to the MainWindow. Calls the Main window's destroy function to destroy any object in the scene.*/
	void Destroy(GameObject*);
/**Spawns an object using the MainWindow function Spawn(int, int, int, double).*/
	void Spawn(int type, int xPos, int yPos, double speed);
	
public slots:
	virtual void Update();
	virtual void OnCollisionEnter(MyList<GameObject*>* gameObjects);
protected :
		MyList<GameObject*>* objects;
		double x;
		double y;
		double vx;
		double vy;
		int width;
		int height;
		bool flipHorizontal;
		double dirX;
		double dirY;
		string type;
		QPixmap* pixmap;
		
		
};

#endif 
