#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"

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

    setFixedSize(1000,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create enmey
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::mousePressEvent(QMouseEvent* event){
    // creat a bullet
    Bullet* bullet = new Bullet();
    bullet->setPos(event->pos());
    bullet->setRotation(40);
    scene->addItem(bullet);
}
