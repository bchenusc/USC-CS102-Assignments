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

#include "bouncingrectangle.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    
    void show();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    BouncingRectangle *item;
    std::vector<BouncingRectangle*> rectangles;
    std::vector<QLabel*> labels;
    std::vector<QPixmap*>pixels;
    int rectangleCounter;
    

public slots:
    void handleTimer();
    void toggleTimer();

};

#endif // MAINWINDOW_H
