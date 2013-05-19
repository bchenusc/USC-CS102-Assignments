
#ifndef GUITILE
#define GUITILE
#include <QGraphicsRectItem>
#include <QLabel>
#include <QObject>
#include <string>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QPen>

class GUITile : public QObject, public QGraphicsRectItem {

	Q_OBJECT
public:
    GUITile(double nx, double ny, double w, double h, int val);
    int getVal();
    void setX( int x );
    void setY( int y );
    void setTargetX(int x);
    void setTargetY(int y);
    int getX();
    int getY();
    void setText(char s);
    void moveTile(int x, int y);
    //Timer for animation variable. Public so i can call everywhere.
		QTimer *timer;
    
signals:
void mouseIsPressed(int i);
void toggleTileInGridIsMoving(bool toggle);

public slots:
	void handleTimer();

protected:
void mousePressEvent(QGraphicsSceneMouseEvent * event);

private:
		int val;
    int x;
    int y;
    int moveTargetX;
    int moveTargetY;
    bool isMoving;
    int width;
    int height;
    QGraphicsSimpleTextItem* gfxTile;
    
};

#endif 
