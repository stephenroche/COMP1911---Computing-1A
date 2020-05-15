// Author: Stephen Roche
// Date created: 13/04/16 - 27/04/16
// Plays Arismet.

#include <stdio.h>

#define MAX_ARISMET_NUMBERS 13

int main (void) {

/* The program calculates the highest score for each rule individually, and then
   returns the rule with the highest score (or the first rule alphabetically in
   the case of a tie).

   As well as the highest score for each rule, enough of the variables are saved
   until the print stage such that the numbers used to make that score can be re-
   printed (e.g. seqMaxStart, seqMaxLength, seqMaxStep). */

    int numbers[MAX_ARISMET_NUMBERS];
    int i, j, nums, evenMax, oddMax, runMax, seqMax, scoreMax;
    int evenOne, evenTwo, evenThree;
    int oddOne, oddTwo, oddThree;
    int runCount, runMaxNumber, runMaxLength;
    int seqStep, seqLength, seqContinue, seqLargest, seqMaxStart, seqMaxStep;
    int seqMaxLength, seqNewWinner;

    // Scan in numbers

        // First integer scanned gives the number of following integers

    scanf("%d", &nums);

    i = 0;
    while (i < nums) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }

    // Even-triple

        // Even-triple and odd-triple start from numbers[nums - 1] and work
        // backwards to find the largest numbers first.

        // The mod-2 operator in each case tests if the number is odd/even.

    evenOne = 0;
    evenTwo = 0;
    evenThree = 0;

    i = (nums - 1);
    while (i >= 0) { 
        if ((numbers[i] % 2) == 0) {

        // if statements test if each of the three largest even numbers have
        // already been filled.

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

        // If evenOne == 0, then there are fewer than three even numbers in the
        // input.

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

        // if statements test if each of the three largest odd numbers have
        // already been filled.

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

        // If oddOne == 0, then there are fewer than three odd numbers in the
        // input.

    if (oddOne != 0) { 
        oddMax = oddOne + oddTwo + oddThree + 1;
    } else {
        oddMax = 0;
    }

    // Run

        // For each integer in numbers[], counts how many of the following
        // integers are the same number.

        // A run must be at least two integers in length.

        // If a new run is found with a higher score than the previous higher
        // scoring run, the highest scoring run is updated.

        // If multiple runs are found with the same score, the run of the
        // smallest integer wins.

    runMax = 0;
    i = 0;
    while (i < nums) {
        runCount = 1;

        while ((runCount + i < nums) && (numbers[i + runCount] == numbers[i])) {
            runCount = runCount + 1;
        }

        // if statement tests if a new highest run is found.

        // Code finds runs of smallest integers first, so any new runs must have
        // a higher score (not equal) in order to replace the previous winning
        // run.

        if ((runCount != 1) && ((runCount * runCount * numbers[i] - 13) > runMax)) {
            runMax = runCount * runCount * numbers[i] - 13;
            runMaxNumber = numbers[i];
            runMaxLength = runCount;        
        }
        i = i + 1;
    }

    // Sequence

        // For each starting integer and each possible step size between 1 and
        // 15, the code tests how long a sequence can be made using these
        // parameters.

        // The sequence can go past 31 and 'circle back' to the start of the
        // month similar to using the mod 31 operation (e.g. {29,31,2,4}).

        // Where 1 is subtracted from a number before, and added back on to that
        // number after performing a mod 31 operation, that is included so that
        // the number 31 remains as 31 and is not replaced by 0.

        // Step sizes of 16 to 30 are not included as these sequences are
        // equivalent to reversing a sequence of a smaller step size (e.g.
        // {10,20,30,9} vs {9,30,20,10}).

        // If multiple sequences tie for the highest score, the sequence with the
        // smallest starting number wins. If there is still a tie the sequence
        // with the smallest second number wins.

    seqMax = 0;
    seqMaxStart = 0;
    seqMaxStep = 0;
    seqMaxLength = 0;

    i = 0;
    while (i < nums) {
        seqStep = 1;

        while (seqStep <= 15) {
            seqLength = 0;
            seqContinue = 1;
            seqLargest = numbers[i];

            while (seqContinue == 1) {
                seqContinue = 0;

        // While loop checks if any of the integers in the array match the next
        // expected number in the sequence.

        // Also updates the largest number in the sequence.

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

        // if statement replaces the previous winning sequence if the new
        // sequence has a higher score.

        // Sequences must have a length of at least 3 integers.

        // else if statement determines the winner for cases of equal scores:

        // If the new sequence has a different starting number, then its starting
        // number must be higher than that of the previous winning sequence and
        // therefore the new sequence does not take priority.

        // If the new sequence has the same starting number and a smaller second
        // number than the previous winning sequence, then it takes priority
        // instead.

            seqNewWinner = 0;

            if ((seqLength >= 3) && ((seqLength * seqLargest - 42) > seqMax)) {

                seqNewWinner = 1;

            } else if ((seqLength >= 3) && 
                       ((seqLength * seqLargest - 42) == seqMax) && 
                       (numbers[i] == seqMaxStart) && 
                       (((numbers[i] + seqStep - 1) % 31 + 1) < 
                            ((seqMaxStart + seqMaxStep - 1) % 31 + 1))) 
                      {

                seqNewWinner = 1;
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

        // If multiple rules tie for the highest score, the rule that is
        // alphabetically first wins.

        // The variables that are saved from the winning rule are used to
        // reconstruct the numbers used to make that score.

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

        // if statement adds a comma after all but the last number in the
        // sequence.

            if (i != (seqMaxLength - 1)) {
                printf(",");
            }
            i = i + 1;
        }

        printf("} scoring %d.\n", seqMax);
    }

    return 0;
}
