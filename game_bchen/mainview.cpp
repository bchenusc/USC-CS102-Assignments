/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "mainview.h"

/**Default Constructor that calls the QGraphicsView constructor
* @param scene The child scene of the view.
*/
MainView::MainView(QGraphicsScene* scene) : QGraphicsView(scene){

} 
/**Default destructor*/
MainView::~MainView(){

}
/**Handles the mouse movement on the view. Tells the main window to tell the turret to look at the mouse cursor.
*	@param mouseEvent The data returned by moving the mouse on the screen.
*/
void MainView::mouseMoveEvent(QMouseEvent* mouseEvent){
	emit mouse(mouseEvent->x(), mouseEvent->y());
}
/**Handles the clicking of the mouse on the view. Tells the main window to tell the turret to fire a bullet.
* @param mouseEvent The data returned by clicking the mouse on the screen.
*/
void MainView::mousePressEvent(QMouseEvent* mouseEvent){
	emit mousePressed(mouseEvent->x(), mouseEvent->y());
}
