#include "BrownTower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"

extern Game* game;

BrownTower::BrownTower(QGraphicsItem *parent){
    //set the graphics
    setPixmap(QPixmap(":/images/qi-browntower.jpeg"));

    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(acquire_target()));
    timer->start(1000);
}

void BrownTower::fire(){
    Bullet* bullet = new Bullet();
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44), attack_dest);
    int angle = -1*ln.angle();
    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void BrownTower::acquire_target(){
    Tower::acquire_target();
}
