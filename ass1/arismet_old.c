// Author: Stephen Roche
// Date created: 13/04/16 - 15/04/16
// Plays Arismet.

#include <stdio.h>

int main (void) {

// The program calculates the highest score for each rule individually, and then returns the rule with the highest score (or the first rule alphabetically in the case of a tie).

// As well as the highest score for each rule, enough of the variables are saved until the print stage such that the numbers used to make that score can be re-printed (e.g. seqMaxStart, seqMaxLength, seqMaxStep).

// For two different runs of numbers giving the same maximum score for run rule (e.g. 6 4 4 4 4 16 16), the number with the smaller first digit wins. If there is still a tie the number with the smallest second digit wins (single digit numbers count as smaller).

// For two different sequences giving the same maximum score for sequence rule (e.g. 7 5 8 12 13 24 26 31, {31,12,24,5} = {31,13,26,8} = 82), priority is given to the starting number with the smallest first digit, then smallest second digit, then smallest first digit of the second number in the sequence, then smallest second digit of the second number. After this stage there is no possibly of there still being a tie.



    #define MAX_ARISMET_NUMBERS 13

    int numbers[MAX_ARISMET_NUMBERS];
    int i, j, nums, evenMax, oddMax, runMax, seqMax, scoreMax;
    int evenOne, evenTwo, evenThree;
    int oddOne, oddTwo, oddThree;
    int runCount, runMaxNumber, runMaxLength, runMaxFirstDigit, runTestFirstDigit;
    int seqStep, seqLength, seqContinue, seqLargest, seqMaxStart, seqMaxStep, seqMaxLength;
    int seqNewWinner, seqMaxStartDigit, seqTestStartDigit, seqMaxSecondDigit, seqTestSecondDigit;

    // Scan in numbers
        // First integer scanned gives the number of following integers

    scanf("%d", &nums);

    i = 0;
    while (i < nums) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }

    // Even-triple
        // Even-triple and odd-triple start from numbers[nums - 1] and work backwards to find the largest numbers first.
        // The mod-2 operator in each case tests if the number is odd/even.

    evenOne = 0;
    evenTwo = 0;
    evenThree = 0;

    i = (nums - 1);
    while (i >= 0) { 
        if ((numbers[i] % 2) == 0) {

        // if statements test if each of the three largest even numbers have already been filled.

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

        // If evenOne == 0, then there are fewer than three even numbers in the input.

    if (evenOne != 0) { 
        evenMax = evenOne + evenTwo + evenThree + 2;
    } else {
        evenMax = 0;
    }

    // Odd-triple
        // Same basic form as even-triple.

    oddOne = 0;
    oddTwo = 0;
    oddThree = 0;

    i = (nums - 1);
    while (i >= 0) { 
        if ((numbers[i] % 2) == 1) {

        // if statements test if each of the three largest odd numbers have already been filled.

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

        // If oddOne == 0, then there are fewer than three odd numbers in the input.

    if (oddOne != 0) { 
        oddMax = oddOne + oddTwo + oddThree + 1;
    } else {
        oddMax = 0;
    }

    // Run
        // For each integer in numbers[], counts how many of the following integers are the same number.
        // A run must be at least two integers in length.
        // If a new run is found with a higher score than the previous higher scoring run, the highest scoring run is updated.
        // If multiple runs are found with the same score, the integer with the smallest first digit wins.

    runMax = 0;
    i = 0;
    while (i < nums) {
        runCount = 1;
        while ((runCount + i < MAX_ARISMET_NUMBERS) && (numbers[i + runCount] == numbers[i])) {
            runCount = runCount + 1;
        }

        // if statement tests if a new highest run is found.

        if ((runCount != 1) && ((runCount * runCount * numbers[i] - 13) > runMax)) {
            runMax = runCount * runCount * numbers[i] - 13;
            runMaxNumber = numbers[i];
            runMaxLength = runCount;

        // If runs have the same score, reduces both current max and test integers to their first digit, then compares for lowest.
        // All variables are ints so dividing a two-digit number by ten just gives their first digit.

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
        // For each starting integer and each possible step size between 1 and 15, the code tests how long a sequence can be made using these parameters.
        // The sequence can go past 31 and 'circle back' to the start of the month similar to using the mod 31 operation (e.g. {29,31,2,4}).
        // Where 1 is subtracted from a number before, and added back on to that number after performing a mod 31 operation, that is included so that the number 31 remains as 31 and is not mapped to 0.
        // Step sizes of 16 to 30 are not included as these sequences are equivalent to reversing a sequence of a smaller step size (e.g. {10,20,30,9} vs {9,30,20,10}).

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
                        if (numbers[j] > seqLargest) {
                            seqLargest = numbers[j];
                        }
                    }
                    j = j + 1;
                }
                seqLength = seqLength + 1;
            }
// Now test for score

            seqNewWinner = 0;

            if ((seqLength >= 3) && ((seqLength * seqLargest - 42) > seqMax)) {
                seqNewWinner = 1;

            } else if ((seqLength >= 3) && ((seqLength * seqLargest - 42) == seqMax)) {
                if (numbers[i] >= 10) {
                    seqTestStartDigit = numbers[i] / 10;
                } else {
                    seqTestStartDigit = numbers[i];
                }
                if (seqMaxStart >= 10) {
                    seqMaxStartDigit = seqMaxStart / 10;
                } else {
                    seqMaxStartDigit = seqMaxStart;
                }
                if (seqTestStartDigit < seqMaxStartDigit) {
                    seqNewWinner = 1;

                } else if (numbers[i] == seqMaxStart) {
                    if (((numbers[i] + seqStep - 1) % 31 + 1) >= 10) {
                        seqTestSecondDigit = ((numbers[i] + seqStep - 1) % 31 + 1) / 10;
                    } else {
                        seqTestSecondDigit = ((numbers[i] + seqStep - 1) % 31 + 1);
                    }
                    if (((seqMaxStart + seqMaxStep - 1) % 31 + 1) >= 10) {
                        seqMaxSecondDigit = ((seqMaxStart + seqMaxStep - 1) % 31 + 1) / 10;
                    } else {
                        seqMaxSecondDigit = ((seqMaxStart + seqMaxStep - 1) % 31 + 1);
                    }
                        
                    if (seqTestSecondDigit < seqMaxSecondDigit) {
                        seqNewWinner = 1;

                    } else if ((seqTestSecondDigit == seqMaxSecondDigit) && (((numbers[i] + seqStep - 1) % 31 + 1) < ((seqMaxStart + seqMaxStep - 1) % 31 + 1))) {
                        seqNewWinner = 1;
                    }
                }
            }

            if (seqNewWinner == 1) {
                seqMax = (seqLength * seqLargest - 42);
                seqMaxStart = numbers[i];
                seqMaxStep = seqStep;
                seqMaxLength = seqLength;
            }

            seqStep = seqStep + 1;
        }
        i = i + 1;
    }

    // Choose highest score
        // Finds the highest score out of all four rules.

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
        // If multiple rules tie for the highest score, the rule that is alphabetically first wins.
        // The variables that are saved from the winning rule are used to reconstruct the numbers used to make that score.

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

        // if statement adds a comma after all but the last number in the sequence.

            if (i != (seqMaxLength - 1)) {
                printf(",");
            }
            i = i + 1;
        }
        printf("} scoring %d.\n", seqMax);
    }

    return 0;
}
