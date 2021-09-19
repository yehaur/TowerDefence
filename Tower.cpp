#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>

Tower::Tower(QGraphicsItem* parent){
    //set the graphics
    setPixmap(QPixmap(":/images/qt-tower.jpeg"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0)<< QPoint(2,0)<< QPoint(3,1)<< QPoint(3,2)<<
              QPoint(2,3)<< QPoint(1,3)<< QPoint(0,2)<< QPoint(0,1);
    //scale points
    int SCALE_FACTOR = 40;
    for (size_t i = 0;  i< points.size(); i++) {
        points[i] *= SCALE_FACTOR;
    }

    // create a polygon from points
    QPolygonF polygon(points);


    //create the QGraphicsPolygonItem
    attack_area =  new QGraphicsPolygonItem(polygon, this);

    // move the polygon
    QPointF poly_center(1.5, 1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+22, y()+22);
    QLineF ln(poly_center, tower_center);
    attack_area->setPos(x()+ln.dx(), y()+ln.dy());
}
