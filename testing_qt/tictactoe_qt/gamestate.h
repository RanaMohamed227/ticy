// gamestate.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <iostream> // Add this for std::cout

class GameState : public QObject
{
    Q_OBJECT
public:
    explicit GameState(int n, int player);
    ~GameState();

    void deepCopy(GameState *copy);
    void printBoard();
    int otherPlayer(int currentPlayer);
    void changePlayer();
    void makeMove(int &move);
    int getBoardSize();
    int* getBoard();
    int getCurrentPlayer();
    void initiate();
    void endGame(int winner);

signals:

public slots:

private:
    int boardSize;
    int currentPlayer;
    int *board;
    QSqlDatabase mydb;

    const int player1 = 1; // Define player1 and player2 as constants
    const int player2 = 2;

    void saveGameToDatabase(int Finish, int winner);
};

#endif // GAMESTATE_H
