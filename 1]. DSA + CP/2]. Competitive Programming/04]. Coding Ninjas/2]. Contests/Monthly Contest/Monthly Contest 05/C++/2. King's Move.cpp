/*
    Time Complexity : O(1)
    Space Complexity : O(1)
*/

#include <vector>
#include <math.h>
using namespace std;
int numberOfMoves(int kx, int ky, int rx1, int ry1, int rx2, int ry2) {

    // Initialise an integer variable 'countMoves' to store the number of moves that can be made.
    int countMoves = 0;

    /*
        Initialise a 'dx' array and set it to {1, 1, -1, -1, 0, 1, 0, -1}, representing 
        the directions of all eight adjacent squares.
    */
    int dx[] = {1, 1, -1, -1, 0, 1, 0, -1};

    /*
        Initialise a 'dy' array and set it to {1, -1, 1, -1, 1, 0, -1, 0}, representing 
        the directions of all eight adjacent squares.
    */
    int dy[] = {1, -1, 1, -1, 1, 0, -1, 0};

    // Iterate from 'i' = 0 to 'i' = 7.
    for (int i = 0; i < 8; i++) {

        // Initialise an integer variable 'currentX' to store the x coordinate of adjacent cell.
        int currentX = kx + dx[i];

        // Initialise an integer variable 'currentY' to store the y coordinate of adjacent cell.
        int currentY = ky + dy[i];

        // Check if the coordinates of adjacent cell are in the range of '[0,7]'. 
        if (currentX >= 0 && currentX <= 7 && currentY >= 0 && currentY <= 7) {

            /*
                 Check if 'currentX' is not equal to 'rx1' and 'rx2', and 'currentY' is not 
                 equal to 'ry1' and 'ry2.
            */
            if (currentX != rx1 && currentX != rx2 && currentY != ry1 && currentY != ry2) {

                // If true, then it is a safe square, increment the 'countMoves'.
                countMoves++;
            }
        }
    }

    // Return 'countMoves'.
    return countMoves;
}