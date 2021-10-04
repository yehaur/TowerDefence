#include "RedTower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"

extern Game* game;

RedTower::RedTower(QGraphicsItem *parent){
    //set the graphics
    setPixmap(QPixmap(":/images/qt-greytower.jpeg"));

    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(acquire_target()));
    timer->start(1000);
}

void RedTower::fire(){
    Bullet* bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/qt-fireball.jpeg"));
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44), attack_dest);
    int angle = -1*ln.angle();
    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void RedTower::acquire_target(){
    Tower::acquire_target();
}
