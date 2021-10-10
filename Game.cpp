#include "Game.h"
#include <QGraphicsScene>
#include "BrownTower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BuildBrownTowerIcon.h"
#include "BuildGreenTowerIcon.h"
#include "BuildRedTowerIcon.h"
#include <QTimer>
#include <QGraphicsItem>

Game::Game(){
    // create a scene
    scene  = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);


    // set the scene
    setScene(scene);

    //create a tower
    Tower* t = new Tower();
    t->setPos(350,250);
    scene->addItem(t);

    //set cursor
    cursor = NULL;
    gcursor = NULL;
    rcursor = NULL;
    build = NULL;
    gbuild = NULL;
    rbuild = NULL;
    setMouseTracking(true);

    setFixedSize(1000,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create enmey
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    pointsToFollow << QPointF(800,0) << QPointF(450, 450) << QPointF(0, 600);
    createEnemies(5);
    //Enemy* enemy = new Enemy();
    //scene->addItem(enemy);

    //create a road
    createRoad();

    //BuildTowerIcon* ic = new BuildTowerIcon();
    //scene->addItem(ic);

    //test code
    BuildBrownTowerIcon* bt = new BuildBrownTowerIcon();
    scene->addItem(bt);

    BuildGreenTowerIcon* gt = new BuildGreenTowerIcon();
    gt->setPos(x(), y()+100);
    scene->addItem(gt);

    BuildRedTowerIcon* rt = new BuildRedTowerIcon();
    rt->setPos(x(),y()+200);
    scene->addItem(rt);
}

void Game::setCursor(QString filename){
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);

    if(gcursor){
        scene->removeItem(gcursor);
        delete gcursor;
    }

    gcursor = new QGraphicsPixmapItem();
    gcursor->setPixmap(QPixmap(filename));
    scene->addItem(gcursor);

    if(rcursor){
        scene->removeItem(rcursor);
        delete rcursor;
    }

    rcursor = new QGraphicsPixmapItem();
    rcursor->setPixmap(QPixmap(filename));
    scene->addItem(rcursor);
}

void Game::mousePressEvent(QMouseEvent* event){
    /*
    // creat a bullet
    Bullet* bullet = new Bullet();
    bullet->setPos(event->pos());
    bullet->setRotation(40);
    scene->addItem(bullet);
    */
    if(build){
        //return if the cursor is colliding with a existing tower
        QList<QGraphicsItem*> items = cursor->collidingItems();
        for(int i=0; i<items.size(); i++){
            if(dynamic_cast<BrownTower*>(items[i]))
                return;
        }

        // otherwise build at the clicked position
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = NULL;
        build = NULL;
    }else{
        QGraphicsView::mousePressEvent(event);
    }

    if(gbuild){
        //return if the cursor is colliding with a existing tower
        QList<QGraphicsItem*> items = gcursor->collidingItems();
        for(int i=0; i<items.size(); i++){
            if(dynamic_cast<GreenTower*>(items[i]))
                return;
        }

        // otherwise build at the clicked position
        scene->addItem(gbuild);
        gbuild->setPos(event->pos());
        gcursor = NULL;
        gbuild = NULL;
    }else{
        QGraphicsView::mousePressEvent(event);
    }

    if(rbuild){
        //return if the cursor is colliding with a existing tower
        QList<QGraphicsItem*> items = rcursor->collidingItems();
        for(int i=0; i<items.size(); i++){
            if(dynamic_cast<RedTower*>(items[i]))
                return;
        }

        // otherwise build at the clicked position
        scene->addItem(rbuild);
        rbuild->setPos(event->pos());
        rcursor = NULL;
        rbuild = NULL;
    }else{
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if(cursor){
        cursor->setPos(event->pos());
    }
    if(gcursor){
        gcursor->setPos(event->pos());
    }
    if(rcursor){
        rcursor->setPos(event->pos());
    }
}

void Game::createEnemies(int numberOfEnemies){
    enemiesSpawned = 0;
    maxNumberOfEnemies = numberOfEnemies;
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    spawnTimer->start(1000);
}

void Game::createRoad(){
    for(int i=0; i<pointsToFollow.size()-1; i++){
        // crreat a line connect two adjacent points
        QLineF line(pointsToFollow[i], pointsToFollow[i+1]);
        QGraphicsLineItem* lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
        scene->addItem(lineItem);
    }
}

void Game::spawnEnemy() {
      // spawn an enemy
    Enemy* enemy = new Enemy(pointsToFollow);
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);
    enemiesSpawned += 1;

    if(enemiesSpawned >= maxNumberOfEnemies){
        spawnTimer->disconnect();
    }
}
