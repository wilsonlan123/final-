#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

// Declares the printBoard function which prints the game board
void printBoard(const std::vector<std::vector<char> >& board);

// Declares the checkWin function which checks if the specified player has won
bool checkWin(const std::vector<std::vector<char> >& board, char player);

// Declares the checkTie function which checks for a tie in the game
bool checkTie(const std::vector<std::vector<char> >& board);

// Declares the playGame function which controls the gameplay
void playGame();

#endif // TICTACTOE_H
