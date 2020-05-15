// Author: Stephen Roche
// Date created: 13/04/16
// Plays Arismet.

#include <stdio.h>

int main (void) {

    #define MAX_ARISMET_NUMBERS 13

    int numbers[MAX_ARISMET_NUMBERS];
    int i, j, nums, evenMax, oddMax, runMax, seqMax, scoreMax;
    int evenOne, evenTwo, evenThree;
    int oddOne, oddTwo, oddThree;
    int runCount, runMaxNumber, runMaxLength, runMaxFirstDigit, runTestFirstDigit;
    int seqStep, seqLength, seqContinue, seqLargest, seqMaxStart, seqMaxStep, seqMaxLength, seqMaxStartDigit, seqTestStartDigit, SeqMaxSecondDigit, SeqTestSecondDigit;

    scanf("%d", &nums);

    i = 0;
    while (i < nums) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }

    // Even-triple

    evenOne = 0;
    evenTwo = 0;
    evenThree = 0;

    i = (nums - 1);
    while (i >= 0) { 
        if ((numbers[i] % 2) == 0) {
            if (evenThree == 0) {
                evenThree = numbers[i];
            } else if (evenTwo == 0) {
                evenTwo = numbers[i];
            } else if (evenOne == 0) {
                evenOne = numbers[i];
            }
        }
        i = i - 1;
    }

    if (evenOne != 0) { 
        evenMax = evenOne + evenTwo + evenThree + 2;
    } else {
        evenMax = 0;
    }

    // Odd-triple

    oddOne = 0;
    oddTwo = 0;
    oddThree = 0;

    i = (nums - 1);
    while (i >= 0) { 
        if ((numbers[i] % 2) == 1) {
            if (oddThree == 0) {
                oddThree = numbers[i];
            } else if (oddTwo == 0) {
                oddTwo = numbers[i];
            } else if (oddOne == 0) {
                oddOne = numbers[i];
            }
        }
        i = i - 1;
    }

    if (oddOne != 0) { 
        oddMax = oddOne + oddTwo + oddThree + 1;
    } else {
        oddMax = 0;
    }

    // Run

    runMax = 0;
    i = 0;
    while (i < nums) {
        runCount = 1;
        while ((runCount + i < MAX_ARISMET_NUMBERS) && (numbers[i + runCount] == numbers[i])) {
            runCount = runCount + 1;
        }
        if ((runCount != 1) && ((runCount * runCount * numbers[i] - 13) > runMax)) {
            runMax = runCount * runCount * numbers[i] - 13;
            runMaxNumber = numbers[i];
            runMaxLength = runCount;
        } else if ((runCount != 1) && ((runCount * runCount * numbers[i] - 13) == runMax)) {
            if (numbers[i] >= 10) {
                runTestFirstDigit = numbers[i] / 10;
            } else {
                runTestFirstDigit = numbers[i];
            }
            if (runMaxNumber >= 10) {
                runMaxFirstDigit = runMaxNumber / 10;
            } else {
                runMaxFirstDigit = runMaxNumber;
            }
            
            if (runTestFirstDigit < runMaxFirstDigit) {
                runMax = runCount * runCount * numbers[i] - 13;
                runMaxNumber = numbers[i];
                runMaxLength = runCount;
            }
            
        }

        i = i + 1;
    }

    // Sequence

    seqMax = 0;
    i = 0;
    while (i < nums) {
        seqStep = 1;
            while (seqStep <= 15) {
                seqLength = 0;
                seqContinue = 1;
                seqLargest = numbers[i];
                while (seqContinue == 1) {
                    seqContinue = 0;
                    j = 0;
                    while (j < nums) {
                        if (numbers[j] == (numbers[i] + (seqStep * (seqLength + 1)) - 1) % 31 + 1) {
                            seqContinue = 1;
//printf("eeeee\n");
                            if (numbers[j] > seqLargest) {
                                seqLargest = numbers[j];
                            }
                        }
                        j = j + 1;
//printf("i\n");
                    }
                    seqLength = seqLength + 1;
//printf("aaa\n");
                }
// Now test for score

                if ((seqLength >= 3) && ((seqLength * seqLargest - 42) > seqMax)) {
                    seqMax = (seqLength * seqLargest - 42);
                    seqMaxStart = numbers[i];
                    seqMaxStep = seqStep;
                    seqMaxLength = seqLength;
                }

// add else if (==)

                seqStep = seqStep + 1;
            }
        i = i + 1;
    }

//printf("seqMax = %d\n", seqMax);







    // Choose highest score

    scoreMax = evenMax;
    if (oddMax > scoreMax) {
        scoreMax = oddMax;
    }
    if (runMax > scoreMax) {
        scoreMax = runMax;
    }
    if (seqMax > scoreMax) {
        scoreMax = seqMax;
    }

    // Print result

    if (evenMax == scoreMax) {
        printf("Even-triple {%d,%d,%d} scoring %d.\n", evenOne, evenTwo, evenThree, evenMax);
    } else if (oddMax == scoreMax) {
        printf("Odd-triple {%d,%d,%d} scoring %d.\n", oddOne, oddTwo, oddThree, oddMax);
    } else if (runMax == scoreMax) {
        printf("Run {");
        i = 1;
        while (i < runMaxLength) {
            printf("%d,", runMaxNumber);
            i = i + 1;
        }
        printf("%d} scoring %d.\n", runMaxNumber, runMax);
    } else {
        printf("Sequence {");
        i = 0;
        while (i < seqMaxLength) {
            printf("%d", ((seqMaxStart + i * seqMaxStep) - 1) % 31 + 1);
            if ((i + 1) != seqMaxLength) {
                printf(",");
            }
            i = i + 1;
        }
        printf("} scoring %d.\n", seqMax);
    }




    return 0;
}
