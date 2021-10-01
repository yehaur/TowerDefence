#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent=0);
    double distanceTo(QGraphicsItem* item);
public slots:
    void attack_target();
    void acquire_target();
private:
    QGraphicsPolygonItem* attack_area;
    QPointF attack_dest;
    bool has_target;

};

#endif // TOWER_H
