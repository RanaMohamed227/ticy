#include <QApplication>
#include <QStackedWidget>
#include "widget.h"
#include "board.h"
#include "agent.h"
#include "humanplayer.h"
#include "game.h"
#include "login.h"
#include "startup.h"

void createConnection() {
    // Database connection setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("games.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS games ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "square1 TEXT, square2 TEXT, square3 TEXT, "
               "square4 TEXT, square5 TEXT, square6 TEXT, "
               "square7 TEXT, square8 TEXT, square9 TEXT, "
               "date TIMESTAMP DEFAULT CURRENT_TIMESTAMP, "
               "game_status TEXT, winner TEXT)");
}

void insertGameData(const QString &square1, const QString &square2, const QString &square3,
                    const QString &square4, const QString &square5, const QString &square6,
                    const QString &square7, const QString &square8, const QString &square9,
                    const QString &game_status, const QString &winner) {
    QSqlQuery query;
    query.prepare("INSERT INTO games (square1, square2, square3, square4, square5, square6, "
                  "square7, square8, square9, game_status, winner) "
                  "VALUES (:square1, :square2, :square3, :square4, :square5, :square6, "
                  ":square7, :square8, :square9, :game_status, :winner)");

    query.bindValue(":square1", square1);
    query.bindValue(":square2", square2);
    query.bindValue(":square3", square3);
    query.bindValue(":square4", square4);
    query.bindValue(":square5", square5);
    query.bindValue(":square6", square6);
    query.bindValue(":square7", square7);
    query.bindValue(":square8", square8);
    query.bindValue(":square9", square9);
    query.bindValue(":game_status", game_status);
    query.bindValue(":winner", winner);

    if (!query.exec()) {
        qDebug() << "Error: insert failed" << query.lastError();
    } else {
        qDebug() << "Data inserted successfully!";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initialize players, game state, and game board
    Player *player1 = new HumanPlayer(1);
    Player *player2 = new HumanPlayer(2);
    Player *player3 = new Agent(1);
    Player *player4 = new Agent(2);

    GameState *state = new GameState(9, player1->getPlayerNumber());
    Board *board = new Board(state);
    Game *game = new Game(player1, player2, player3, player4, board, state);

    // Initialize the main game window
    Widget *window = new Widget(board, game);
    board->setParent(window);
    window->setWindowTitle("Tic Tac Toe");

    // Initialize the stacked widget and add login and startup pages
    QStackedWidget *stackedWidget = new QStackedWidget();
    login *loginwindow = new login();
    startup *startupPage = new startup();
    stackedWidget->addWidget(loginwindow);
    stackedWidget->addWidget(startupPage);
    stackedWidget->addWidget(window); // Add the game window to the stacked widget

    stackedWidget->setMinimumSize(617, 355); // Adjust size as needed

    // Show the stacked widget with the login page initially
    stackedWidget->show();

    // Connect signals and slots for login window interactions
    QObject::connect(loginwindow, &login::logInSuccessful, [stackedWidget, window, game]() {
        stackedWidget->setCurrentIndex(2); // Start the game
    });

    QObject::connect(loginwindow, &login::signUpRequested, [stackedWidget]() {
        stackedWidget->setCurrentIndex(1); // Show the startup page
    });

    // Connect signals and slots for startup window interactions
    QObject::connect(startupPage, &startup::signUpSuccessful, [stackedWidget, window, game]() {
        stackedWidget->setCurrentIndex(0); // Show the login page
    });

    QObject::connect(startupPage, &startup::logInRequested, [stackedWidget]() {
        stackedWidget->setCurrentIndex(0); // Show the login page
    });

    // Connect gameEnded signal from Game class
    QObject::connect(game, &Game::gameEnded, [state](int winner) {
        // Handle game ended event here, e.g., save game data
        QString winnerStr = (winner == 1) ? "X" : "O";
        insertGameData("X", "O", "X", "O", "X", "O", "X", "O", "X", "finished", winnerStr);
    });

    createConnection(); // Set up the database connection

    return a.exec();
}
