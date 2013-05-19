/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#include "Background.h"

/** Background constructor that constructs a scrollable background that scrolls to the right with a given pixmap.
* Must a provide a horizontally tiled background for the scrolling to look decent.
* Calls the GameObject constructor to construct the image.
* Default speed is set to 1.
* Tag: "Background"
* @param nx Spawn X location of Background (+X is rightwards)
* @param ny Spawn Y location of Background (+Y is downwards)(
* @param nz Spawn Depth location of Background (+Z is more front)
* @param pixmap The picture the Background is to display.
*/
Background::Background(int nx, int ny, int nz, QPixmap* pixmap):GameObject( nx,  ny, nz, pixmap){
	speed=1;
	type="Background";
}

/** Default Background Destructor.
*/
Background::~Background(){

}

/** Update function called every millisecond. Handles Background scrolling to the left.
* Background is destroyed if it's X position moves too far off the screen.
*/
void Background:: Update(){
	MoveDir(-1,0,0.5*speed);
	if (gX()<= -1000 || gX()>=1500|| gY()<= -1000 || gY()>=1000){
			emit Destroy(this);
	}
}

/** Sets the scroll speed of the background.
* @param i The new scrolling speed.
*/
void Background::setSpeed(int i){
	speed = i;
}

