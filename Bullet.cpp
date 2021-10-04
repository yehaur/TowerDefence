#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Bullet::Bullet(QGraphicsItem* parent){
    // set graphics
    setPixmap(QPixmap(":/images/qt-bullet"));

    // connect a timer to move
    QTimer* move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()), this,SLOT(move()));
    move_timer->start(50);

    maxRange = 100;
    distanceTravalled = 0;
}

void Bullet::move(){
    int STEP_SIZE = 15;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}

double Bullet::getMaxRange(){
    return maxRange;
}

double Bullet::getDistanceTravalled(){
    return distanceTravalled;
}

void Bullet::setMaxRange(double &dist){
    maxRange = dist;
}

void Bullet::setDistanceTravalled(double &distTravel){
    distanceTravalled = distTravel;
}

