#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* parent=0);
public slots:
    void move();
    double getMaxRange();
    double getDistanceTravalled();
    void setMaxRange(double&);
    void setDistanceTravalled(double&);
private:
    double maxRange;
    double distanceTravalled;
};

#endif // BULLET_H
