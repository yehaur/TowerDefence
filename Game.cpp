#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BuildTowerIcon.h"

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
    build = NULL;
    setMouseTracking(true);

    setFixedSize(1000,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create enmey
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);

    BuildTowerIcon* ic = new BuildTowerIcon();
    scene->addItem(ic);
}

void Game::setCursor(QString filename){
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
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
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = NULL;
        build = NULL;
    }else{
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if(cursor){
        cursor->setPos(event->pos());
    }
}
