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
}

void Bullet::move(){
    int STEP_SIZE = 10;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
