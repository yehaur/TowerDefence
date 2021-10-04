#include "BuildGreenTowerIcon.h"
#include "GreenTower.h"
#include "Game.h"

extern Game* game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/qt-greentower.jpeg"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->gbuild){
        game->gbuild = new GreenTower();
        game->setCursor(QString(":/images/qt-greentower.jpeg"));
    }
}
