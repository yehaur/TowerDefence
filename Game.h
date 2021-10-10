#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Tower.h"
#include "BrownTower.h"
#include "GreenTower.h"
#include "RedTower.h"

class Game:public QGraphicsView{
       Q_OBJECT
public:
    Game();
    void setCursor(QString filename);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void createEnemies(int numberOfEnemies);
    void createRoad();

    //member attributes
    QGraphicsScene* scene;
    QGraphicsPixmapItem* cursor;
    QGraphicsPixmapItem* gcursor;
    QGraphicsPixmapItem* rcursor;
    BrownTower* build;
    GreenTower* gbuild;
    RedTower* rbuild;
    QTimer* spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;
public slots:
    void spawnEnemy();
};

#endif // GAME_H
