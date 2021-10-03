#include "BuildTowerIcon.h"
#include "Game.h"

extern Game* game;

BuildTowerIcon::BuildTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/qt-tower.jpeg"));
}

void BuildTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->build){
        game->build = new Tower();
        game->setCursor(QString(":/images/qt-tower.jpeg"));
    }
}
