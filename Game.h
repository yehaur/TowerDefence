#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class Game:public QGraphicsView{
public:
    Game();
    QGraphicsScene* scene;
};

#endif // GAME_H
