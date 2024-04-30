#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <string>
#include "tictactoe.h"

void printBoard(const std::vector<std::vector<char> >& board) {
    std::cout << "\n";
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < board.size() - 1) std::cout << "---------\n";
    }
    std::cout << "\n";
}

bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkTie(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    std::cout << "Player 1 is X  |  Player 2 is 0" << std::endl;
    std::vector<std::vector<char> > board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    while (true) {
        printBoard(board);
        std::cout << "Player " << currentPlayer << ", enter row and column to place " << currentPlayer << ": ";
        std::cin >> row >> col;
        if (std::cin.fail() || row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore wrong input
            std::cout << "Invalid move. Try again.\n";
            continue;
        }
        board[row - 1][col - 1] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::string win;
            std::cout << "Player " << currentPlayer << " wins!\n";
            std::ofstream fout;
            fout.open("counting.txt", std::ios::app);
            if (fout.fail()) {
                std::cout << "Error in file opening!" << std::endl;
                exit(1);
            }
            if (currentPlayer == 'X'){
                win = "Player 1";
                fout << win << std::endl;
                fout.close();
            }
            else{
                win = "Player 2";
                fout << win << std::endl;
                fout.close();  
            }
            break;
        }
        if (checkTie(board)) {
            printBoard(board);
            std::cout << "It's a tie!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }
}
