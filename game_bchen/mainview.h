/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef MAINVIEW
#define MAINVIEW

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class MainView : public QGraphicsView {
    Q_OBJECT
    
public:
     MainView(QGraphicsScene* scene);
    ~MainView();
    void mouseMoveEvent(QMouseEvent* mouseEvent);
   	void mousePressEvent(QMouseEvent* mouseEvent);
    
signals:
/**A signal that is emitted when the mouse is moving inside the main view.
*/
	void mouse(int, int);
/**A signal that is emitted when the mouse is pressed inside the main view.*/
	void mousePressed(int, int);

};

#endif // MAINWINDOW_H
