// Author: Stephen Roche
// Date created: 18/04/16
// Determines the winner of noughts and crosses.

#include <stdio.h>

#define SIZE 3

int main (void) {

    int ttt[SIZE][SIZE];
    int i, j, winner, cont;

    printf("Please enter the board:\n");

// Scan board

    i = 0;

    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            scanf("%d", &ttt[j][i]);
            j = j + 1;
        }

        i = i + 1;
    }

// Print board

    printf("Here is the board:\n\n");

    i = 0;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            if (ttt[j][i] == 0) {
                printf("O");
            } else if (ttt[j][i] == 1) {
                printf("X");
            } else {
                printf(".");
            }
            if (j != (SIZE - 1)) {
                printf(" ");
            }
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }

    printf("\n");    

    winner = 2;

// Row winner

    j = 0;
    while (j < SIZE) {
        i = 1;
        cont = 1;
        while ((i < SIZE) && (cont == 1)) {
            if (ttt[i][j] != ttt[0][j]) {
                cont = 0;
            }
            i = i + 1;
        }
        if (cont == 1 && (ttt[0][j] != 2)) {
            winner = ttt[0][j];
        }
        j = j + 1;
    }

// Column winner

    j = 0;
    while (j < SIZE) {
        i = 1;
        cont = 1;
        while ((i < SIZE) && (cont == 1)) {
            if (ttt[j][i] != ttt[j][0]) {
                cont = 0;
            }
            i = i + 1;
        }
        if (cont == 1 && (ttt[j][0] != 2)) {
            winner = ttt[j][0];
        }
        j = j + 1;
    }

// Left diagonal winner

    i = 1;
    cont = 1;
    while ((i < SIZE) && (cont == 1)) {
        if (ttt[i][i] != ttt[0][0]) {
            cont = 0;
        }
        i = i + 1;
    }
    if (cont == 1 && (ttt[0][0] != 2)) {
        winner = ttt[0][0];
    }

// Right diagonal winner

    i = 1;
    cont = 1;
    while ((i < SIZE) && (cont == 1)) {
        if (ttt[SIZE - 1 - i][i] != ttt[SIZE - 1][0]) {
            cont = 0;
        }
        i = i + 1;
    }
    if (cont == 1 && (ttt[SIZE - 1][0] != 2)) {
        winner = ttt[SIZE - 1][0];
    }

// Print winner

    if (winner == 0) {
        printf("Noughts win\n");
    } else if (winner == 1) {
        printf("Crosses win\n");
    } else {
        printf("There are no winners\n");
    }

    return 0;
}

