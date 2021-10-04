#include "BuildBrownTowerIcon.h"
#include "BrownTower.h"
#include "Game.h"

extern Game* game;

BuildBrownTowerIcon::BuildBrownTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/qi-browntower.jpeg"));
}

void BuildBrownTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->build){
        game->build = new BrownTower();
        game->setCursor(QString(":/images/qi-browntower.jpeg"));
    }
}
