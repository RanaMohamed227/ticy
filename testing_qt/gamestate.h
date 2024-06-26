#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
    GameState(int boardSize, int currentPlayer);
    ~GameState();

    int getBoardSize() const;
    int getCurrentPlayer() const;
    void setCurrentPlayer(int player);

    bool isValidMove(int move) const;
    void makeMove(int move);
    bool isGameOver() const;
    bool isGameWon() const;
    void deepCopy(GameState* other) const;

private:
    int boardSize;
    int currentPlayer;
    int* board; // 1D array representing the game board

    bool checkWinCondition() const; // Internal method to check win condition
};

#endif // GAMESTATE_H
