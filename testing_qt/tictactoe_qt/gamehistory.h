#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QObject>
#include <QSqlDatabase>
#include <QVector>
#include <QPair>

class GameHistory : public QObject
{
    Q_OBJECT
public:
    explicit GameHistory(QObject *parent = nullptr);
    void addGame(int gameId, const QVector<QPair<int, int>>& moves);
    QVector<QPair<int, int>> getGameMoves(int gameId);

private:
    QSqlDatabase game_db;
    bool openDatabase();
    void closeDatabase();
};

#endif // GAMEHISTORY_H
