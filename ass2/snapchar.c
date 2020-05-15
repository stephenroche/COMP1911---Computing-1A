// Author: Stephen Roche - z5059764
// stephen-roche@hotmail.com
// Date created: 17/05/16 - 25/05/16
// Analyses a binary image to determine which letter is represented in it.

/* The program calculates all of the required parameters of the letter in
 * separate functions and prints them to stdout within the function processImage.

 * It also calculates five other parameters to help with the identification of
 * letters (holeHeight, slopingEdge, straightness, rightTilt and isC).

 * In most cases each function calculates a single parameter, except for holes
 * which calculates three and returns two as pointers.
 */

#include <stdio.h>
#include <math.h>

#define MAX_X               20
#define MAX_Y               20
#define MAX_HOLES_ISLANDS   15
#define HOLE_EMPTY          0
#define VALID_HOLE          -1
#define INVALID_HOLE        -2
#define ISLAND_EMPTY        0
#define VALID_ISLAND        -1
#define C_CORNER_SIZE       3

void printImage(int image[MAX_X][MAX_Y]);


int pixelCount(int image[MAX_X][MAX_Y]);
int height(int image[MAX_X][MAX_Y]);
int width(int image[MAX_X][MAX_Y]);
double diagonal(int width, int height);
double tallness(int width, int height);
double blackness(int pixelCount, int width, int height);
double horiBalance(int image[MAX_X][MAX_Y], int pixelCount, int width, 
                   int height);
double vertBalance(int image[MAX_X][MAX_Y], int pixelCount, int width, 
                   int height);

int holes(int image[MAX_X][MAX_Y], int width, int height, double *holeness, 
          int pixelCount, double *holeHeight);
int holePixelCount(int hole[MAX_X][MAX_Y + 1]);
int inArrays(int holes[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1], int x, int y);
int expandHole(int image[MAX_X][MAX_Y], int width, int height, 
               int holes[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1], int holeNumber, 
               int x, int y, int xShift, int yShift);

int islands(int image[MAX_X][MAX_Y], int width, int height);
int expandIsland(int image[MAX_X][MAX_Y], int width, int height, 
                 int islands[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1], 
                 int islandNumber, int x, int y);

int slopingEdge(int image[MAX_X][MAX_Y]);
double straightness(int image[MAX_X][MAX_Y], int width, int height);
double rightTilt(int image[MAX_X][MAX_Y], int width, int height);
double isC(int image[MAX_X][MAX_Y], int width, int height);

char letter(double tallness, double blackness, double horiBalance, 
            double vertBalance, int holes, int islands, double holeness, 
            double holeHeight, int slopingEdge, double straightness, 
            double rightTilt, double isC);

void processImage(int image[MAX_X][MAX_Y]) {

    int pixelCountValue = pixelCount(image);
    int heightValue = height(image);
    int widthValue = width(image);
    double diagonalValue = diagonal(widthValue, heightValue);
    double tallnessValue = tallness(widthValue, heightValue);
    double blacknessValue = blackness(pixelCountValue, widthValue, heightValue);
    double horiBalanceValue = horiBalance(image, pixelCountValue, widthValue, heightValue);
    double vertBalanceValue = vertBalance(image, pixelCountValue, widthValue, heightValue);

    double holenessValue = 0;
    double holeHeightValue = 0;
    int holesValue = holes(image, widthValue, heightValue, &holenessValue, pixelCountValue, &holeHeightValue);
    int islandsValue = islands(image, widthValue, heightValue);

    int slopingEdgeValue = slopingEdge(image);
    double straightnessValue = straightness(image, widthValue, heightValue);
    double rightTiltValue = rightTilt(image, widthValue, heightValue);
    double isCValue = isC(image, widthValue, heightValue);


    char letterChar = letter(tallnessValue, blacknessValue, horiBalanceValue, 
vertBalanceValue, holesValue, islandsValue, holenessValue, holeHeightValue, 
slopingEdgeValue, straightnessValue, rightTiltValue, isCValue);


    printf("Pixel-count: %d\n", pixelCountValue);
    printf("Height: %d\n", heightValue);
    printf("Width: %d\n", widthValue);
    printf("Diagonal: %.6lf\n", diagonalValue);
    printf("Tallness: %.6lf\n", tallnessValue);
    printf("Blackness: %.6lf\n", blacknessValue);

    printf("Horizontal-balance: %.6lf\n", horiBalanceValue);
    printf("Vertical-balance: %.6lf\n", vertBalanceValue);

    printf("Holes: %d\n", holesValue);
    printf("Holeness: %.6lf\n", holenessValue);
    printf("Islands: %d\n", islandsValue);

    printf("Letter: %c\n", letterChar);

/*  printf("Hole height: %.6lf\n", holeHeightValue);
    printf("Straightness: %.6lf\n", straightnessValue);
    printf("Right tilt: %.6lf\n", rightTiltValue);
    printf("Is C: %.6lf\n", isCValue); */
}

// The functions pixelCount - blackness are fairly straightforward and so don't
// need many comments.

// Sorry for the duplication in the pixel counting functions. I was tempted to
// change the size of the image array so that I could use the same function for
// both purposes, but decided that I shouldn't try to edit the starting point
// code.

int pixelCount(int image[MAX_X][MAX_Y]) {
    int pixelCount = 0;
    int x, y;

    for (y = (MAX_Y - 1); y >= 0; y--) {
        for (x = 0; x < MAX_X; x++) {
            if (image[x][y] == 1) {
                pixelCount++;
            }
        }
    }

    return pixelCount;
}


int holePixelCount(int hole[MAX_X][MAX_Y + 1]) {
    int pixelCount = 0;
    int x, y;

    for (y = (MAX_Y - 1); y >= 0; y--) {
        for (x = 0; x < MAX_X; x++) {
            if (hole[x][y] == 1) {
                pixelCount++;
            }
        }
    }

    return pixelCount;
}

// height sweeps down from the top until it finds a black pixel; width does the
// same but from the right.

int height(int image[MAX_X][MAX_Y]) {
    int x, y;

    for (y = (MAX_Y - 1); y >= 0; y--) {
        for (x = 0; x < MAX_X; x++) {
            if (image[x][y] == 1) {
                return (y + 1);
            }
        }
    }

    return 0;
}


int width(int image[MAX_X][MAX_Y]) {
    int x, y;

    for (x = (MAX_X - 1); x >= 0; x--) {
        for (y = (MAX_Y - 1); y >= 0; y--) {
            if (image[x][y] == 1) {
                return (x + 1);
            }
        }
    }

    return 0;
}


double diagonal(int width, int height) {
    return sqrt(width * width + height * height);
}


double tallness(int width, int height) {
    return (double)height / width;
}


double blackness(int pixelCount, int width, int height) {
    return (double)pixelCount / (width * height);
}

// Horizontal-balance is the mean of the x-values of the centre-of-mass of the
// pixels as a fraction of the width of the letter.

// The centre-of-mass of a pixel is taken to be it's x-coordinate + 0.5.

double horiBalance(int image[MAX_X][MAX_Y], int pixelCount, int width, int height) {
    int x, y;
    int weightedTotal = 0;
    double balance;

    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            if (image[x][y] == 1) {
                weightedTotal += x;
            }
        }
    }

    balance = (double)weightedTotal / pixelCount + 0.5;

    return balance / width;
}


double vertBalance(int image[MAX_X][MAX_Y], int pixelCount, int width, int height) {
    int x, y;
    int weightedTotal = 0;
    double balance;

    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            if (image[x][y] == 1) {
                weightedTotal += y;
            }
        }
    }

    balance = (double)weightedTotal / pixelCount + 0.5;

    return balance / height;
}

// The holes function stores individual holes as '1' pixels in separate arrays
// with the same coordinates as the image array, but with an extra row on top to
// allow for the tagging of the arrays as either blank, containing a valid hole,
// or containing an invalid hole.

// The function scans through the letter until it finds a white pixel. It then
// tests if any of that pixel's four neighbours is also a white pixel and adds
// them to the hole if they are. It then repeats this process for every pixel in
// the hole until the hole has reached its maximal size.

// If any member of the hole touches the edge of the array or the white space to
// the top and right of the letter, the hole is tagged as in invalid hole.

// This process is repeated until all holes have been found.

// holeness and holeHeight are also calculated in this function and returned as
// pointers.

int holes(int image[MAX_X][MAX_Y], int width, int height, double *holeness, 
          int pixelCount, double *holeHeight) {
    int holes[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1] = {{{0}}};
    int i, j, holeNumber, holeGrowing, x, y;
    int nHoles = 0;

    for (i = 1; i < (width - 1); i++) {
        for (j = 1; j < (height - 1); j++) {
            if (image[i][j] == 0 && inArrays(holes, i, j) == 0) {
                holeNumber = 0;

                while (holes[holeNumber][0][MAX_Y] != HOLE_EMPTY && holeNumber < MAX_HOLES_ISLANDS - 1) {
                    holeNumber++;
                }

                holes[holeNumber][i][j] = 1;
                holes[holeNumber][0][MAX_Y] = VALID_HOLE;
                holeGrowing = 1;

                while (holeGrowing != 0) {
                    holeGrowing = 0;

                    for (x = 1; x < (width - 1); x++) {
                        for (y = 1; y < (height - 1); y++) {
                            if (holes[holeNumber][x][y] == 1) {
                                holeGrowing += expandHole(image, width, height, holes, holeNumber, x, y, 1, 0);
                                holeGrowing += expandHole(image, width, height, holes, holeNumber, x, y, -1, 0);
                                holeGrowing += expandHole(image, width, height, holes, holeNumber, x, y, 0, 1);
                                holeGrowing += expandHole(image, width, height, holes, holeNumber, x, y, 0, -1);
                            }

                        }
                    }
                }
                if (holes[holeNumber][0][MAX_Y] == VALID_HOLE) {
                    nHoles++;
                }
            }
        }
    }

// holeness finds the hole array with the largest number of 1 pixels and returns
// that number of pixels divided by the number of black pixels in the letter
// itself.

// holeHeight returns the height of the bottom of the largest hole in a letter as
// a fraction of the total height of that letter.

// It's very useful as a way to differentiate between an a and an e, as well as
// g's from (b & d).

    int largestHole = 0;

    for (holeNumber = 0; holeNumber < MAX_HOLES_ISLANDS; holeNumber++) {
        if (holes[holeNumber][0][MAX_Y] == VALID_HOLE && holePixelCount(holes[holeNumber]) > largestHole) {

            largestHole = holePixelCount(holes[holeNumber]);

            *holeHeight = 0;
            j = 1;
            while (j < height - 1 && *holeHeight == 0) {
                for (i = 1; i < width - 1; i++) {
                    if (holes[holeNumber][i][j] == 1) {
                        *holeHeight = (j + 0.5) / height;
                    }
                }
                j++;
            }
        }
    }

    *holeness = (double)largestHole / pixelCount;

    return nHoles;
}

// inArrays is used to check if a point is already a member of an island or a
// hole.

int inArrays(int arrays[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1], int x, int y) {
    int i;
    for (i = 0; i < MAX_HOLES_ISLANDS; i++) {
        if (arrays[i][x][y] == 1) {
            return 1;
        }
    }
    return 0;
}

// expandHole returns 1 if a new point is found to help test if a hole is still
// growing or not.

int expandHole(int image[MAX_X][MAX_Y], int width, int height, 
               int holes[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1], int holeNumber, 
               int x, int y, int xShift, int yShift) {

    if (image[x + xShift][y + yShift] == 0 && holes[holeNumber][x + xShift][y + yShift] == 0) {
        holes[holeNumber][x + xShift][y + yShift] = 1;
        
        if ((x + xShift == 0) || (x + xShift == width - 1) || (y + yShift == 0) 
            || (y + yShift == height - 1)) {
            holes[holeNumber][0][MAX_Y] = INVALID_HOLE;
        }

        return 1;
    }
    return 0;
}

// The islands function is very similar to holes except that there cannot be
// 'invalid' islands.

int islands(int image[MAX_X][MAX_Y], int width, int height) {
    int islands[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1] = {{{0}}};
    int i, j, islandNumber, islandGrowing, x, y;
    int nIslands = 0;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (image[i][j] == 1 && inArrays(islands, i, j) == 0) {
                islandNumber = 0;

                while (islands[islandNumber][0][MAX_Y] != ISLAND_EMPTY 
                       && islandNumber < MAX_HOLES_ISLANDS - 1) {
                    islandNumber++;
                }

                islands[islandNumber][i][j] = 1;
                islands[islandNumber][0][MAX_Y] = VALID_ISLAND;
                islandGrowing = 1;

                while (islandGrowing != 0) {
                    islandGrowing = 0;

                    for (x = 0; x < width; x++) {
                        for (y = 0; y < height; y++) {
                            if (islands[islandNumber][x][y] == 1) {
                                islandGrowing += expandIsland(image, width, height, islands, islandNumber, x, y);
                            }

                        }
                    }
                }
                if (islands[islandNumber][0][MAX_Y] == VALID_ISLAND) {
                    nIslands++;
                }
            }
        }
    }
    return nIslands;
}

// expandIsland tests if any of a pixel's eight neighbours are also black and
// adds them to the current island if they are.

int expandIsland(int image[MAX_X][MAX_Y], int width, int height, 
                 int islands[MAX_HOLES_ISLANDS][MAX_X][MAX_Y + 1], 
                 int islandNumber, int x, int y) {
    int xShift, yShift;
    int pixelsAdded = 0;

    for (xShift = -1; xShift <= 1; xShift++) {
        for (yShift = -1; yShift <= 1; yShift++) {

            if ((x + xShift) != -1 && (x + xShift) != width && (y + yShift) != -1 
                && (y + yShift) != height && image[x + xShift][y + yShift] == 1 
                && islands[islandNumber][x + xShift][y + yShift] == 0) {

                islands[islandNumber][x + xShift][y + yShift] = 1;
                pixelsAdded++;
            }
        }
    }

    if (pixelsAdded != 0) {
        return 1;
    }

    return 0;
}

// The slopingEdge function tests if the letter's lower-right edge is sloping or
// not.

// Only really useful for differentiating k from (f & h).

int slopingEdge(int image[MAX_X][MAX_Y]) {
    int x;

    for (x = MAX_X - 1; x >= 0; x--) {
        if (image[x][1] == 1) {
            if (image[x][2] == 1) {
                return 0;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

// The straightness function determines how straight a letter's right face is.

// Calculated as the number of rightmost pixels that have the same x-coordinate
// as the middle-rightmost pixel, as a fraction of the total height.

// Useful for finding l.

double straightness(int image[MAX_X][MAX_Y], int width, int height) {
    int x, y, midWidth, straightTotal;
    straightTotal = 0;
    midWidth = 0;

    x = width - 1;
    while (x >= 0 && midWidth == 0) {
        if (image[x][height / 2] == 1) {
            midWidth = x;
        }
        x--;
    }

    for (y = 0; y < height; y++) {
        x = width - 1;
        while (x >= 0 && image[x][y] != 1) {
            x--;
        }
        if (x == midWidth) {
            straightTotal++;
        }
    }

    return (double)straightTotal / height;
}

// rightTilt roughly determines if a letter's right face tilts towards the right
// or the left. 

// Calculated first by splitting the letter into a top and bottom half. Then by
// taking the difference between the averages of the x-components of the
// rightmost pixels in each row for each half, and dividing by the width.

// Helpful in differentiating h from f.

double rightTilt(int image[MAX_X][MAX_Y], int width, int height) {
    int x, y, midpoint, rowWidth;
    double topWidth = 0;
    double bottomWidth = 0;
    midpoint = height / 2;
    
    for (y = 0; y <= midpoint; y++) {
        rowWidth = 0;
        x = width - 1;
        while (x >= 0 && rowWidth == 0) {

            if (image[x][y] == 1) {
                rowWidth = x;
                bottomWidth += x;
            }
            x--;
        }
    }
    bottomWidth = bottomWidth / (midpoint + 1);

    for (y = midpoint + 1; y < height; y++) {
        rowWidth = 0;
        x = width - 1;
        while (x >= 0 && rowWidth == 0) {

            if (image[x][y] == 1) {
                rowWidth = x;
                topWidth += x;
            }
            x--;
        }
    }
    topWidth = topWidth / (height - midpoint - 1);

    return (topWidth - bottomWidth) / width;
}

// isC only exists to find how much like c a letter looks.

// Finds the number of black pixels as a fraction of the total length for the
// left column, bottom row and top row, excluding corners.

double isC(int image[MAX_X][MAX_Y], int width, int height) {
    int x, y, pointCount, pixelCount, cornerSize;
    pointCount = 0;
    pixelCount = 0;
    cornerSize = width / C_CORNER_SIZE;

    for (y = cornerSize; y < height - cornerSize; y++) {
        if (image[0][y] == 1) {
            pixelCount++;
        }
    }
    for (x = cornerSize; x < width - 1; x++) {
        if (image[x][0] == 1) {
            pixelCount++;
        }
    }
    for (x = cornerSize; x < width - 1; x++) {
        if (image[x][height - 1] == 1) {
            pixelCount++;
        }
    }

    pointCount = height + 2 * width - 4 * cornerSize - 2;

    return (double)pixelCount / pointCount;
}


// The letter identification function differenciates the letters a-m first by the
// number of islands (splitting off i and j), then by the number of holes and
// then by a variety of other parameters, narrowing down the number of possible
// letters each time.

// a and g can both have either one or two holes, so they are identified in two
// separate sections.

char letter(double tallness, double blackness, double horiBalance, 
            double vertBalance, int holes, int islands, double holeness, 
            double holeHeight, int slopingEdge, double straightness, 
            double rightTilt, double isC) {
    char letter = '?';

    if (islands >= 2) { // Contains (i & j)
        if (horiBalance < 0.58) { // i is symmetrical, j is more right-heavy
            letter = 'i';
        } else {
            letter = 'j';
        }

    } else {
        if (holes >= 2) { // Contains (a & g)
            if (tallness > 1.2) { // g is taller than a
                letter = 'g';
            } else {
                letter = 'a';
            }

        } else if (holes == 1) { // Contains (a, b, d, e & g)

// (b, d & g) are generally taller than (a & e), however there was an e with the
// same tallness as a d, so d is also more bottom-heavy than e.
            if (tallness > 1.34 || (tallness > 1.28 && vertBalance < 0.45)) {
                if (holeHeight > 0.33) { // The hole in g is higher than (b & d)
                    letter = 'g';
                } else {
                    if (horiBalance > 0.5) { // d is right-heavy, b is left-heavy
                        letter = 'd';
                    } else {
                        letter = 'b';
                    }
                }
            } else {
                if (holeHeight < 0.48) { // The hole in a is lower than in e
                    letter = 'a';
                } else {
                    letter = 'e';
                }
            }

        } else { // Contains (c, f, h, k, l & m)
            if (tallness < 1) { // m is the only letter shorter than it is wide
                letter = 'm';
            } else if (tallness == 1) { // c (like m) can also be square shaped
                if (horiBalance > 0.473) { // m is symmetrical, c is left-heavy
                    letter = 'm';
                } else {
                    letter = 'c';
                }
            } else {
                if (straightness > 0.82) { // l is much straighter than (c, k, f
                                           // & h)
                    letter = 'l';
                } else if (isC > 0.75) { // isC finds how much like c a letter is
                    letter = 'c';
                } else if (slopingEdge == 1) { // (f & h) do not have a sloping
                                               // edge
                    letter = 'k';
                } else if (rightTilt > -0.1) { // f tilts to the right, h tilts
                                               // to the left
                    letter = 'f';
                } else {
                    letter = 'h';
                }
            }
        }
    }

    return letter;
}

// End of my functions.





// This function prints the image which you may find useful for debugging
void printImage(int image[MAX_X][MAX_Y]) {
    int x, y;

    y = MAX_Y - 1;
    while (y >= 0) {
        x = 0;
        while (x < MAX_X) {
            if (image[x][y] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
            x = x + 1;
        }
        printf("\n");
        y = y - 1;
    }
    return;
}

//
// You do not need to understand the code below here.
//
// You do not need to change the code below here.
//
// If you wish to modify the code below, you have
// probably misunderstood the assignment specification
//


void readImage(FILE *stream, int image[MAX_X][MAX_Y]);

int main(int argc, char *argv[]) {
    int image[MAX_X][MAX_Y];
    FILE *f;
    int i;

    if (argc == 1) {
        readImage(stdin, image);
        processImage(image);
        return 0;
    }

    for (i = 1; i < argc; i = i + 1) {
        f = fopen(argv[i], "r");
        if (f == NULL) {
            fprintf(stderr, "image2letter: Can not open image file '%s'", argv[i]);
            return 1;
        }
        readImage(f, image);
        processImage(image);
    }
    return 0;
}


void readImage(FILE *stream, int image[MAX_X][MAX_Y]) {
    char line[4096];
    int y, x;

    for (y = MAX_Y - 1; y >= 0; y = y - 1) {
        if (fgets(line, sizeof line, stream) == NULL)
            break;
        if (line[0] == 'P' && y == MAX_Y - 1) {
            // PBM file (hopefully ascii) - skip dimensions
            fgets(line, sizeof line, stream);
            fgets(line, sizeof line, stream);
        }
        for (x = 0; x < MAX_X; x = x + 1) {
            if (line[x] == '\0' || line[x] == '\n') {
                break;
            } else if (line[x] == '0' || line[x] == ' ') {
                image[x][y] = 0;
            } else {
                image[x][y] = 1;
            }
        }
        // zero remainder of the row
        for (; x < MAX_X; x = x + 1)
            image[x][y] = 0;
    }
    // zero any remaining rows
    for (; y >= 0; y = y - 1)
        for (x = 0; x < MAX_X; x = x + 1)
            image[x][y] = 0;
}






