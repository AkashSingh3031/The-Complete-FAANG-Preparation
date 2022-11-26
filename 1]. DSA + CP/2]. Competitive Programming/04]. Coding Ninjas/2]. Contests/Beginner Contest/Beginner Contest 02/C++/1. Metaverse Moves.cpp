/*
    Time complexity: O(1)
    Space complexity: O(1)
*/

int isPossibleToReach(int x1, int y1, int x2, int y2, int x, int y) {
    // Checking for both the conditions.
    if (abs(x1 - x2) <= x and abs(y1 - y2) <= y) {
        return 1;
    } else {
        return 0;
    }
}
