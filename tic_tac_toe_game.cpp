#include <iostream>
using namespace std;


void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool isMoveValid(char board[3][3], int row, int col);
bool checkForWin(char board[3][3], char player);
bool checkForDraw(char board[3][3]);
void switchPlayer(char &currentPlayer);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameEnd = false;
    int row, col;

    initializeBoard(board);

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    while (!gameEnd) {
        displayBoard(board);

        
        cout << "Player " << currentPlayer << ", enter your move (row [1-3] and column [1-3]): ";
        cin >> row >> col;


        row--;
        col--;
        if (isMoveValid(board, row, col)) {
            board[row][col] = currentPlayer;
            if (checkForWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnd = true;
            }
            else if (checkForDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameEnd = true;
            }
            else {
                switchPlayer(currentPlayer);
            }
        } else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        cout << "Thank you for playing Tic-Tac-Toe! Goodbye." << endl;
    }

    return 0;
}
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}
void displayBoard(char board[3][3]) {
    cout << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
    cout << endl;
}
bool isMoveValid(char board[3][3], int row, int col) {
    if (board[row][col] == ' ') {
        return true;
    } else {
        return false;
    }
}
bool checkForWin(char board[3][3], char player) {
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
bool checkForDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}