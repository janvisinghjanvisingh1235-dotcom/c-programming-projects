#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

int makeMove(int choice, char symbol) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9) {
        return 0;
    }

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return 0;
    }

    board[row][col] = symbol;
    return 1;
}

int checkWinner() {

    for (int i = 0; i < 3; i++) {

        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return 1;
        }

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int checkDraw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O') {
                return 0;
            }
        }
    }

    return 1;
}

int main() {

    int choice;
    int player = 1;
    char symbol;

    printf("====================================\n");
    printf("          TIC-TAC-TOE GAME\n");
    printf("====================================\n");

    while (1) {

        displayBoard();

        if (player == 1) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }

        printf("\nPlayer %d (%c), enter your choice (1-9): ",
               player, symbol);

        scanf("%d", &choice);

        if (!makeMove(choice, symbol)) {
            printf("\nInvalid move! Try again.\n");
            continue;
        }

        if (checkWinner()) {

            displayBoard();

            printf("\n🎉 Player %d (%c) wins!\n", player, symbol);
            break;
        }

        if (checkDraw()) {

            displayBoard();

            printf("\nIt's a draw!\n");
            break;
        }

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    printf("\nThanks for playing! 🎮\n");

    return 0;
}