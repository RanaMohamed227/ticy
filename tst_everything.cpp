#include <QCoreApplication>
#include <QtTest>
#include "../agent.h"
#include "../gamestate.h"
#include "../board.h"
#include "../game.h"
#include "../gamelogic.h"
#include "../humanplayer.h"
#include "../login.h"
#include "../startup.h"
#include "../widget.h"
#include "ui_login.h"
#include "ui_startup.h"

// add necessary includes here

class everything : public QObject
{
    Q_OBJECT

public:
    everything();
    ~everything();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void testIsHuman();
    void testGetPlayerNumber();
    void testBoardInitialization();
    void testBoardClicking();
    void testSetAllowed();

    void testGameChangeNextPlayer1();
    void testGameChangeNextPlayer2();
    void testGameChangePlayers();
    void testGameRestart();
    void testGameNextRound();

    void testGameLogicGenerateValidMoves();
    void testGameLogicNumOfValidMoves();
    void testGameLogicValidMove();
    void testGameLogicGameOver();
    void testGameLogicGameWon();

    void testGameStateMakeMove();
    void testGameStateChangePlayer();
    void testGameStateInitiate();
    void testGameStatePrintBoard();

    void testHumanPlayerIsHuman();
    void testHumanPlayerGetPlayerNumber();

    void testLoginFunctionality();
    void testStartupFunctionality();
    void testWidgetFunctionality();

private:
    Agent* agent = nullptr;
    GameState* state = nullptr;
    Board* board = nullptr;
    Game* game = nullptr;
    GameLogic* logic = nullptr;
    HumanPlayer* humanPlayer = nullptr;
    login* loginWindow = nullptr;
    startup* startupWindow = nullptr;
    Widget* widget = nullptr;
};

everything::everything() {}

everything::~everything() {
    delete agent;
    delete state;
    delete board;
    delete game;
    delete logic;
    delete humanPlayer;
    delete loginWindow;
    delete startupWindow;
    delete widget;
}

void everything::initTestCase() {
    agent = new Agent(1);  // Initialize the agent with player number 1
    state = new GameState(3, 1);  // Initialize a 3x3 game state with player 1
    board = new Board(state);  // Initialize the board with the game state
    humanPlayer = new HumanPlayer(1);  // Initialize human player with player number 1
    logic = new GameLogic();  // Initialize game logic
    loginWindow = new login();  // Initialize login window
    startupWindow = new startup();  // Initialize startup window
    game = new Game(humanPlayer, humanPlayer, humanPlayer, humanPlayer, board, state);  // Initialize game with human players
    widget = new Widget(board, game);  // Initialize main widget with the board and game
}

void everything::cleanupTestCase() {
    // No additional cleanup necessary
}

void everything::testIsHuman() {
    QCOMPARE(agent->isHuman(), false);  // Agent is not human
}

void everything::testGetPlayerNumber() {
    QCOMPARE(agent->getPlayerNumber(), 1);  // Player number should be 1
}

void everything::testBoardInitialization() {
    QVERIFY(board != nullptr);  // Board should be initialized
    QCOMPARE(board->size(), QSize(300, 300));  // Board should have a size of 300x300 (3x3 tiles of 100x100 each)
}

void everything::testBoardClicking() {
    // Set allowed to true to allow clicking
    board->setAllowed(true);

    // Simulate a mouse press event at position (150, 150)
    QMouseEvent pressEvent(QEvent::MouseButtonPress, QPoint(150, 150), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    QCoreApplication::sendEvent(board, &pressEvent);

    int clickedTile = -1;
    board->getClicked(clickedTile);

    QCOMPARE(clickedTile, 4);  // Click at (150, 150) should correspond to the center tile (1, 1) which is tile 4 in a 3x3 grid
}

void everything::testSetAllowed() {
    board->setAllowed(true);
    QMouseEvent pressEvent(QEvent::MouseButtonPress, QPoint(150, 150), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    QCoreApplication::sendEvent(board, &pressEvent);

    int clickedTile = -1;
    board->getClicked(clickedTile);
    QCOMPARE(clickedTile, 4);  // Click should be allowed and register tile 4

    board->setAllowed(false);
    QCoreApplication::sendEvent(board, &pressEvent);
    board->getClicked(clickedTile);
    QCOMPARE(clickedTile, -1);  // Click should not be allowed and no tile should be registered
}

void everything::testGameChangeNextPlayer1() {
    game->changeNextPlayer1("Human");
    QCOMPARE(game->nextPlayer1, game->player1);
    game->changeNextPlayer1("Computer");
    QCOMPARE(game->nextPlayer1, game->player3);
}

void everything::testGameChangeNextPlayer2() {
    game->changeNextPlayer2("Human");
    QCOMPARE(game->nextPlayer2, game->player2);
    game->changeNextPlayer2("Computer");
    QCOMPARE(game->nextPlayer2, game->player4);
}

void everything::testGameChangePlayers() {
    game->currentPlayer = game->currentPlayer1;
    game->changePlayers();
    QCOMPARE(game->currentPlayer, game->currentPlayer2);
    game->changePlayers();
    QCOMPARE(game->currentPlayer, game->currentPlayer1);
}

void everything::testGameRestart() {
    game->restart();
    QCOMPARE(game->currentPlayer, game->currentPlayer1);
    QCOMPARE(state->getCurrentPlayer(), state->player1);
}

void everything::testGameNextRound() {
    game->nextRound();
    QVERIFY(true);  // This is a placeholder to ensure nextRound can be called without errors
}

void everything::testGameLogicGenerateValidMoves() {
    int validMoves[state->getBoardSize()];
    logic->generateValidMoves(state, validMoves);
    QVERIFY(true);  // Ensure no errors occur
}

void everything::testGameLogicNumOfValidMoves() {
    int num = logic->numOfValidMoves(state);
    QCOMPARE(num, state->getBoardSize());
}

void everything::testGameLogicValidMove() {
    int move = 0;
    int validMoves[state->getBoardSize()];
    int size = state->getBoardSize();
    logic->generateValidMoves(state, validMoves);
    QVERIFY(logic->validMove(move, validMoves, size, state));
}

void everything::testGameLogicGameOver() {
    QVERIFY(!logic->gameOver(state));
}

void everything::testGameLogicGameWon() {
    QVERIFY(!logic->gameWon(state));
}

void everything::testGameStateMakeMove() {
    int move = 0;
    state->makeMove(move);
    QCOMPARE(state->getBoard()[move], state->player1);
}

void everything::testGameStateChangePlayer() {
    int initialPlayer = state->getCurrentPlayer();
    state->changePlayer();
    QCOMPARE(state->getCurrentPlayer(), state->otherPlayer(initialPlayer));
}

void everything::testGameStateInitiate() {
    state->initiate();
    for (int i = 0; i < state->getBoardSize(); ++i) {
        QCOMPARE(state->getBoard()[i], 0);
    }
    QCOMPARE(state->getCurrentPlayer(), state->player1);
}

void everything::testGameStatePrintBoard() {
    state->printBoard();
    QVERIFY(true);  // Ensure no errors occur during print
}

void everything::testHumanPlayerIsHuman() {
    QCOMPARE(humanPlayer->isHuman(), true);
}

void everything::testHumanPlayerGetPlayerNumber() {
    QCOMPARE(humanPlayer->getPlayerNumber(), 1);
}

void everything::testLoginFunctionality() {
    // Simulate login button click
    loginWindow->ui->lineEdit_username->setText("testuser");
    loginWindow->ui->lineEdit_password->setText("testpassword");
    loginWindow->on_pushButton_clicked();
    QVERIFY(true);  // Placeholder to ensure no errors
}

void everything::testStartupFunctionality() {
    // Simulate sign-up button click
    startupWindow->ui->lineEdit_username->setText("testuser");
    startupWindow->ui->lineEdit_password->setText("testpassword");
    startupWindow->on_pushButton_clicked();
    QVERIFY(true);  // Placeholder to ensure no errors
}

void everything::testWidgetFunctionality() {
    widget->showgameboard();
    QVERIFY(true);  // Ensure no errors occur
}

void everything::test_case1() {}

QTEST_MAIN(everything)

#include "tst_everything.moc"
