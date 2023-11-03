/* This is a fun tic tac toe game created using C Programming.
   Group 1: Prativa Koturu (Roll No. 31)
            Srishti Motwani (Roll No. 39)
			Mayank Bajaj (Roll No. 03)
*/

#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the game is over
int isGameOver() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        //to check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        //to check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    //to check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    // Check for a tie
    int isTie = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                isTie = 0;
                break;
            }
        }
    }
    if (isTie) {
        return 2;
    }

    return 0;
}

int main() {
    initializeBoard();
    int result = 0;

    printf("Tic Tac Toe Game\n");

    while (1)
    {
        displayBoard();

        int row, col;
        printf("Player %c, enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
         //invalid move condition
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        result = isGameOver();
        if (result == 1) {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        } else if (result == 2) {
            displayBoard();
            printf("It's a tie!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
