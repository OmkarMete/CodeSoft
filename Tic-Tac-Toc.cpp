#include <iostream>
#include <vector>
#include <string>

using namespace std;

void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool placeMarker(vector<vector<char>>& board, int row, int col, char marker);
bool checkForWin(const vector<vector<char>>& board, char marker);
bool isBoardFull(const vector<vector<char>>& board);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    char playAgain = ' ';

    do {
        initializeBoard(board);

        do {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row [1-3] column [1-3]): ";
            cin >> row >> col;

            row--; col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;

                if (checkForWin(board, currentPlayer)) {
                    gameWon = true;
                    break;
                }

                if (isBoardFull(board)) {
                    gameDraw = true;
                    break;
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                cout << "Invalid move! Please try again.\n";
            }

        } while (!gameWon && !gameDraw);

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            cout << "It's a draw!\n";
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        currentPlayer = 'X';
        gameWon = false;
        gameDraw = false;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(vector<vector<char>>& board, int row, int col, char marker) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = marker;
        return true;
    } else {
        return false;
    }
}

bool checkForWin(const vector<vector<char>>& board, char marker) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker)
            return true;
        if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker)
            return true;
    }

    if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker)
        return true;
    if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker)
        return true;

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
