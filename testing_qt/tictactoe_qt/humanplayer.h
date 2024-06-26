#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

#include "player.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(int);
    void generateNextMove(int&, GameState*);
    bool isHuman();
    int getPlayerNumber();

private:
    int playerNumber;
    bool human;
};

#endif // HUMANPLAYER_H
