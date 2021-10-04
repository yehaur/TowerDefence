#ifndef REDTOWER_H
#define REDTOWER_H

#include "Tower.h"

class RedTower:public Tower{
    Q_OBJECT
public:
    RedTower(QGraphicsItem* parent=0);
    void fire();
public slots:
    void acquire_target();
};

#endif // REDTOWER_H
