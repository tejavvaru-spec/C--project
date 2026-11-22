#include <stdio.h>

// Function to display the board
void displayBoard(char board[3][3]) {
    int i, j;

    printf("\n");

    for (i = 0; i < 3; i++) {
        printf(" ");

        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);

            if (j < 2)
                printf("|");
        }

        printf("\n");

        if (i < 2)
            printf("---|---|---\n");
    }

    printf("\n");
}


}

// Function to check draw
int checkDraw(char board[3][3]) {
    int i, j;
// Function to check winner
int checkWinner(char board[3][3]) {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] >= '1' &&
                board[i][j] <= '9')
                return 0;
        }
    }

    return 1;
}

// Main game function
void playGame() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int position;
    int row, col;
    char player = 'X';

    while (1) {
        displayBoard(board);

        printf("Player %c, enter position (1-9): ", player);

        if (scanf("%d", &position) != 1) {
            printf("Invalid input!\n");
            return;
        }

        if (position < 1 || position > 9) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row = (position - 1) / 3;
        col = (position - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        board[row][col] = player;

        if (checkWinner(board)) {
            displayBoard(board);
            printf("Congratulations! Player %c wins!\n", player);
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            printf("Game Draw!\n");
            break;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n============================");
        printf("\n       TIC-TAC-TOE GAME");
        printf("\n============================");
        printf("\n1. Start Game");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 0;
        }

        switch (choice) {
            case 1:
                playGame();
                break;

            case 2:
                printf("\nThank you for playing!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 2);

    return 0;
}