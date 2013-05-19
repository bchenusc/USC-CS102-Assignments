#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <cmath>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QtGui/QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <iostream>
#include <QGroupBox>
#include <QStyle>
#include <QPlastiqueStyle>
#include <QGridLayout>
#include <QListView>
#include "board.h"
#include "guitile.h"
#include <string>
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include <QListWidget>

#define WINDOW_MAX_X 240
#define WINDOW_MAX_Y 240

enum Heurisitcs{
	MANHATTAN=1,
	OUTOFPLACE=2,
};

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
		void win();
		bool checkIfInt(string s);
    
private:
//Window
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGridLayout *mainWin;

//Text lines
 		QLineEdit *textSize;
    QLineEdit *textMoves;
    QLineEdit *textSeed;
    
//Error box
		QTextEdit* errorSpace;

//Soltuions
		QListWidget* viewSolutions;
		
//The board on screen
		Board* b_;
		bool solved;
		bool startClicked;

//GUI Tile Array
		GUITile** tileArray;
		bool firstTimeRunningGame;
		int size;
		
//Heuristic
		QRadioButton *manhattan;
		QRadioButton *outOfPlace;
		int heur;
		
//Beautiful background
QGraphicsRectItem* bgBox;
		
//Animation
	bool aTileIsMoving;
	


public slots:
	void start();
	void MainWindowmoveTile(int i);
	void toggleHeur();
	void cheat();
	void toggleTileMoving(bool toggle);
};

#endif // MAINWINDOW_H
