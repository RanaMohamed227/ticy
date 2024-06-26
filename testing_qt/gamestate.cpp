#include "gamestate.h"
#include <cstring> // For std::memcpy

GameState::GameState(int size, int player)
    : boardSize(size), currentPlayer(player) {
    board = new int[boardSize];
    std::memset(board, 0, sizeof(int) * boardSize); // Initialize board with 0s
}

GameState::~GameState() {
    delete[] board;
}

int GameState::getBoardSize() const {
    return boardSize;
}

int GameState::getCurrentPlayer() const {
    return currentPlayer;
}

void GameState::setCurrentPlayer(int player) {
    currentPlayer = player;
}

bool GameState::isValidMove(int move) const {
    return move >= 0 && move < boardSize && board[move] == 0;
}

void GameState::makeMove(int move) {
    if (isValidMove(move)) {
        board[move] = currentPlayer;
        currentPlayer = (currentPlayer == 1) ? 2 : 1; // Toggle between players
    }
}

bool GameState::isGameOver() const {
    for (int i = 0; i < boardSize; ++i) {
        if (board[i] == 0) {
            return false;
        }
    }
    return true;
}

bool GameState::isGameWon() const {
    return checkWinCondition();
}

void GameState::deepCopy(GameState* other) const {
    other->boardSize = boardSize;
    other->currentPlayer = currentPlayer;
    std::memcpy(other->board, board, sizeof(int) * boardSize);
}

bool GameState::checkWinCondition() const {
    // Implement the win condition check based on the game logic
    // For simplicity, let's assume a linear win condition (e.g., consecutive elements)
    for (int i = 0; i < boardSize - 2; ++i) {
        if (board[i] != 0 && board[i] == board[i + 1] && board[i] == board[i + 2]) {
            return true;
        }
    }
    return false;
}
