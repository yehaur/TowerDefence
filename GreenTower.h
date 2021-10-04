#ifndef GREENTOWER_H
#define GREENTOWER_H

#include "Tower.h"

class GreenTower:public Tower{
    Q_OBJECT
public:
    GreenTower(QGraphicsItem* parent=0);
    void fire();
public slots:
    void acquire_target();
};

#endif // GREENTOWER_H
