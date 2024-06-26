#include "gamehistory.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

GameHistory::GameHistory(QObject *parent) : QObject(parent)
{
    if (!openDatabase()) {
        qWarning() << "Failed to open database connection!";
        // Handle database connection error
    }
}

bool GameHistory::openDatabase()
{
    game_db = QSqlDatabase::addDatabase("QSQLITE");
    game_db.setDatabaseName("D:/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");

    if (!game_db.open()) {
        qWarning() << "Error: Failed to open database connection:" << game_db.lastError().text();
        return false;
    }

    return true;
}

void GameHistory::closeDatabase()
{
    if (game_db.isOpen()) {
        game_db.close();
    }
}

void GameHistory::addGame(int gameId, const QVector<QPair<int, int>>& moves)
{
    QSqlQuery insertQuery(game_db);
    insertQuery.prepare("INSERT INTO Game_H (game_id, moves) VALUES (:game_id, :moves)");

    QJsonArray jsonArray;
    for (const auto& move : moves) {
        QJsonObject jsonObj;
        jsonObj["row"] = move.first;
        jsonObj["col"] = move.second;
        jsonArray.append(jsonObj);
    }

    QJsonDocument jsonDoc(jsonArray);
    QString history = jsonDoc.toJson(QJsonDocument::Compact);

    insertQuery.bindValue(":game_id", gameId);
    insertQuery.bindValue(":moves", history);

    if (!insertQuery.exec()) {
        qWarning() << "Error inserting game data:" << insertQuery.lastError().text();
        // Handle insertion error
    }
}

QVector<QPair<int, int>> GameHistory::getGameMoves(int gameId)
{
    QVector<QPair<int, int>> moves;

    QSqlQuery selectQuery(game_db);
    selectQuery.prepare("SELECT moves FROM Game_H WHERE game_id = :game_id");
    selectQuery.bindValue(":game_id", gameId);

    if (!selectQuery.exec()) {
        qWarning() << "Error fetching game data:" << selectQuery.lastError().text();
        // Handle fetch error
    } else {
        while (selectQuery.next()) {
            QString history = selectQuery.value("moves").toString();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(history.toUtf8());
            QJsonArray jsonArray = jsonDoc.array();

            for (const QJsonValue& value : jsonArray) {
                QJsonObject jsonObj = value.toObject();
                int row = jsonObj["row"].toInt();
                int col = jsonObj["col"].toInt();
                moves.append(qMakePair(row, col));
            }
        }
    }

    return moves;
}
