// gamestate.cpp
#include "gamestate.h"
#include <QtSql>
GameState::GameState(int n, int player) : QObject(), boardSize(n), currentPlayer(player)
{
    board = new int[boardSize];
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = 0;
    }

    // Initialize the database
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("games.db");
    if (!mydb.open())
    {
        qDebug() << "Failed to open the database:" << mydb.lastError().text();
    }
    else
    {
        qDebug() << "Connected to the database";
    }
}

GameState::~GameState()
{
    delete[] board;
    if (mydb.isOpen())
    {
        mydb.close();
    }
}

void GameState::deepCopy(GameState *copy)
{
    for (int i = 0; i < boardSize; i++)
    {
        copy->getBoard()[i] = board[i];
    }
}

void GameState::printBoard()
{
    int a = sqrt(boardSize);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (board[a * i + j] == 0)
            {
                std::cout << "  ";
            }
            else if (board[a * i + j] == 1)
            {
                std::cout << "x ";
            }
            else if (board[a * i + j] == 2)
            {
                std::cout << "o ";
            }
        }
        std::cout << "\n";
    }
}

int GameState::otherPlayer(int currentPlayer)
{
    return (currentPlayer == player1) ? player2 : player1;
}

void GameState::changePlayer()
{
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

void GameState::makeMove(int &move)
{
    board[move] = currentPlayer;
    changePlayer();
}

int GameState::getBoardSize()
{
    return boardSize;
}

int *GameState::getBoard()
{
    return board;
}

int GameState::getCurrentPlayer()
{
    return currentPlayer;
}

void GameState::initiate()
{
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = 0;
    }
    currentPlayer = player1;
}

void GameState::saveGameToDatabase(int Finish, int winner)
{
    QSqlQuery query;
    query.prepare("INSERT INTO TicTacToeGames (SQ1, SQ2, SQ3, SQ4, SQ5, SQ6, SQ7, SQ8, SQ9, Finish, winner) "
                  "VALUES (:SQ1, :SQ2, :SQ3, :SQ4, :SQ5, :SQ6, :SQ7, :SQ8, :SQ9, :Finish, :winner)");

    // Bind values
    for (int i = 0; i < 9; ++i)
    {
        query.bindValue(QString(":SQ%1").arg(i + 1), board[i]);
    }
    query.bindValue(":Finish", Finish);
    query.bindValue(":winner", winner);

    if (!query.exec())
    {
        qDebug() << "Failed to insert data:" << query.lastError().text();
    }
    else
    {
        qDebug() << "Data inserted successfully";
    }
}

void GameState::endGame(int winner)
{
    int Finish = 1;
    saveGameToDatabase(Finish, winner);
}
