#include <stdio.h>

#define MAX_MOVES 7

int move(int x, int y, int xFinish, int yFinish, int xMoves[], int yMoves[], int *bestMoveCount, int moveCount);

int main(int argc, char *argv[]) {
    int xStart = argv[1][0] -'a'+1;
    int yStart = argv[1][1] - '0';
    int xFinish = argv[2][0] -'a'+1;
    int yFinish = argv[2][1] - '0';

//    printf("Moving from %d,%d to %d,%d\n", xStart, yStart, xFinish, yFinish);
    
    int xMoves[MAX_MOVES];
    int yMoves[MAX_MOVES];
    int bestMoveCount = MAX_MOVES;

    if (move(xStart, yStart, xFinish, yFinish, xMoves, yMoves, &bestMoveCount, 0) == -1) {
        printf("Could not find %s in less than %d moves\n", argv[2], MAX_MOVES);
        return 0;
    }

//    printf("bestMoveCount = %d\n", bestMoveCount);

    int i = 0;
    while (i == 0 || xMoves[i-1] != xFinish || yMoves[i-1] != yFinish) {
        printf("%c%d ", xMoves[i] +'a'-1, yMoves[i]);
        i++;
    }
    printf("\n");

    return 0;
}


int move(int x, int y, int xFinish, int yFinish, int xMoves[], int yMoves[], int *bestMoveCount, int moveCount) {

    int a = -1;
    int b = -1;
    int c = -1;
    int d = -1;
    int e = -1;
    int f = -1;
    int g = -1;
    int h = -1;

    if (moveCount == MAX_MOVES) {
        return -1;
    }

    if (x == xFinish && y == yFinish && moveCount < *bestMoveCount) {
        *bestMoveCount = moveCount;
        xMoves[moveCount] = xFinish;
        yMoves[moveCount] = yFinish;
        return *bestMoveCount;
    }

    if (x+1 <= 8 && y+2 <= 8) {
        a = move(x+1, y+2, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x+2 <= 8 && y+1 <= 8) {
        b = move(x+2, y+1, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x+2 <= 8 && y-1 >= 1) {
        c = move(x+2, y-1, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x+1 <= 8 && y-2 >= 1) {
        d = move(x+1, y-2, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x-1 >= 1 && y-2 >= 1) {
        e = move(x-1, y-2, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x-2 >= 1 && y-1 >= 1) {
        f = move(x-2, y-1, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x-2 >= 1 && y+1 <= 8) {
        g = move(x-2, y+1, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }
    if (x-1 >= 0 && y+2 <= 8) {
        h = move(x-1, y+2, xFinish, yFinish, xMoves, yMoves, bestMoveCount, moveCount+1);
    }


    if (a == *bestMoveCount || b == *bestMoveCount || c == *bestMoveCount || d == *bestMoveCount || e == *bestMoveCount || f == *bestMoveCount || g == *bestMoveCount || h == *bestMoveCount) {

        xMoves[moveCount] = x;
        yMoves[moveCount] = y;
        return *bestMoveCount;
    }

    return -1;
}
