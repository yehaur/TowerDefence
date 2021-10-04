#include "BuildRedTowerIcon.h"
#include "RedTower.h"
#include "Game.h"

extern Game* game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/qt-greytower.jpeg"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->rbuild){
        game->rbuild = new RedTower();
        game->setCursor(QString(":/images/qt-greytower.jpeg"));
    }
}
