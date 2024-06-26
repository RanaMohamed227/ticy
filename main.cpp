#include <QApplication>
#include <QIcon>
#include <QStackedWidget>

#include "widget.h"
#include "board.h"
#include "agent.h"
#include "humanplayer.h"
#include "game.h"
#include "login.h"
#include "startup.h"

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

    return a.exec();
}
