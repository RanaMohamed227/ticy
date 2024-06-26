#ifndef PLAYER
#define PLAYER
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

#include "gamestate.h"

class Player {
public:
    virtual void generateNextMove(int&, GameState*) = 0;
    virtual bool isHuman() = 0;
    virtual int getPlayerNumber() = 0;
};

#endif // PLAYER
