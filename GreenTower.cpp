#include "GreenTower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"

extern Game* game;

GreenTower::GreenTower(QGraphicsItem *parent){
    //set the graphics
    setPixmap(QPixmap(":/images/qt-greentower.jpeg"));

    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(acquire_target()));
    timer->start(1000);
}

void GreenTower::fire(){
    //create the bullets
    Bullet* bullet1 = new Bullet();
    Bullet* bullet2 = new Bullet();
    Bullet* bullet3 = new Bullet();

    //ser the graphics
    bullet1->setPixmap(QPixmap(":/images/qt-bullet"));
    bullet2->setPixmap(QPixmap(":/images/qt-3bullets.jpeg"));
    bullet3->setPixmap(QPixmap(":/images/qt-bullet"));

    bullet1->setPos(x()+44,y()+44);
    bullet2->setPos(x()+44,y()+44);
    bullet3->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44), attack_dest);
    int angle = -1*ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}

void GreenTower::acquire_target(){
    Tower::acquire_target();
}
