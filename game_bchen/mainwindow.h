/* 
		Created By: Brian Chen
	 	See LICENSE.txt for licensing details.
   	Uploaded: 5/19/2013
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QValidator>
#include <QGroupBox>
#include <QFrame>
#include <QGraphicsSimpleTextItem>
#include <QMouseEvent>
#include <QtGui/QApplication>


#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>


#include "GameObject.h"
#include "Background.h"
#include "mylist.h"
#include "Player.h"
#include "Enemy.h"
#include "Missile.h"
#include "Turret.h"
#include "mainview.h"
#include "Boost_Health.h"
#include "DeadlyHamster.h"
#include "ExtraPoints.h"
#include "FollowingMissile.h"

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
		/**Default Constructor of MainWindow. Creates all the buttons, scene, view, window, and initial graphics that appear on the screen.
		* Storess all the images that wil be used in the game in a MyList.
		*/
     MainWindow();
    /**Default destructor of MainWindow. Deletes dynamically allocated things*/
    ~MainWindow();
    /**Handles any key that is pressed in the main window and tells  the Player object to act on the input*/
    void keyPressEvent(QKeyEvent* key);
    void keyReleaseEvent(QKeyEvent* key);
    
signals:
	/**Signal that calls all the game object's OnCollisionEnter function ever millisecond
	* @param gameObjects The list of game objects that populates the scene.
	*/
	void CollisionChecker(MyList<GameObject*>* gameObjects);
    
public slots:
		/**Spawns the enemies either left or right side of the screen. Spawns health at top of screen every 15 seconds.
		* Spawns hamsters from the right every 10 seconds. Increases speed of game every 15 seconds.
		*/
    void handleTimer();
    /** Pauses the game*/
    void toggleTimer();
    /**Starts the game. Allows for enemies to spawn. Changes Start button to a restart button*/
    void startClicked();
    /**Destroys a game object that is passed in. Removes that object from the scene and deletes its dynamic allocation
    *@param toDestroy GameObject that is to be removed from the game permanently.
    */
    void Destroy(GameObject *toDestroy);
    /** Spawn a game object at a location with a speed
    *	@param type The integer case type of object you want to spawn. Corresponding types that can be spawned are listed in the code.
    * @param x	X position of the spawned item.
    * @param y	Y position of the spawned item.
    * @param newSpeed	Speed of the spawned item.
    */
    void Spawn(int type, int x, int y, double newSpeed);
    /** When the player dies or the restart button is hit, the lose function is engaged.
    *	Deletes all gameobjects except for the background on the screen.
    * Puts up a sign that basically says you lose.
    */
    void Lose();
    /** Changes the health bar gui picture depending on the health of the player. 
    *	@param change The integer number the health bar gui should represent.
    */
    void changeHealthBar(int change);
    /** Tells the turret to look at the mouse. 
    * @param mx The x position of the mouse.
    * @param my The y position of the mouse.
    */
    void handleMouse(int mx, int my);
    /** Tells the turret to fire at the mouse position.
    * @param x The x position of the mouse.
    * @param y The y position of the mouse.
    */
   	void mousePressed(int x, int y);
   	/**Adds a certain amount to the game score.
   	*	@param nScore The score to add to the game.
   	*/
   	void AddToScore(int nScore);
    
private:
		
		bool playerIsDead;
		bool startIsClicked;
		bool playerIsSpawned;
		bool gameIsPaused;
		
		void spawnNewUI();
		
    QGraphicsScene *scene;
    MainView *view;
    QGridLayout *mainWin;
    
    QLineEdit *nameBar;
    QTextEdit *systemChat;
    
    //Buttons / UI
    QPushButton *start;
    GameObject* healthBar;
    QGraphicsSimpleTextItem* healthLabel;
    GameObject* introPic;
    QLabel *scoreNumLabel;
    QLabel *levelNumLabel;
    
    //Timers
    QTimer *mainTimer;
    
    //Pics and Objects
    MyList<QPixmap*> pix;
    MyList<GameObject*> gameObjects;
    MyList<QPixmap*> backgrounds;
    
    //Player && Turret
    Player* mainPlayer;
    Turret* mainTurret;
    int score;
    vector<int> highScores;
    vector<string> names;
    void readHighScores();
    void saveHighScore(int score, string name);
    
    //Animations
    MyList<QPixmap*>* playerAnim;
    MyList<QPixmap*>* enemyAnim;
    
    //Settings
    double gameSpeed;
    int gameTime;
    int numberOfBulletsSpawnedByEnemies;
    
    int bgSpawnCounter;
    int RbgSpawnCounter;
    
    int RenemySpawnCounter;
    int enemySpawnCounter;
    
    GameObject* losePic;
    
};

#endif // MAINWINDOW_H
