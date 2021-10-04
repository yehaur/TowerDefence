#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include "BrownTower.h"
#include "GreenTower.h"
#include "RedTower.h"

class Game:public QGraphicsView{
public:
    Game();
    void setCursor(QString filename);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    //member attributes
    QGraphicsScene* scene;
    QGraphicsPixmapItem* cursor;
    QGraphicsPixmapItem* gcursor;
    QGraphicsPixmapItem* rcursor;
    BrownTower* build;
    GreenTower* gbuild;
    RedTower* rbuild;
};

#endif // GAME_H
