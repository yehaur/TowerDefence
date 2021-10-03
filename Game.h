#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"

class Game:public QGraphicsView{
public:
    Game();
    void setCursor(QString filename);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    //member attributes
    QGraphicsScene* scene;
    QGraphicsPixmapItem* cursor;
    Tower* build;
};

#endif // GAME_H
