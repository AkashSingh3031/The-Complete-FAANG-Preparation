/*
    Time Complexity: O(N * log(M))
    Space Complexity: O(1)

    Where, 'N' is the number of ninjas, and 'M' is the number of paintings to be painted.
*/
bool canPaint(long long currTime, int &m, int &k, vector<int>&a) {
    int n = a.size();

    // Calculate the number of shift by taking 'floor(currTime/k)'.

    long long numberofShifts = (currTime) / (1LL * k);
    if (numberofShifts < 1) {
        // If there are no shifts, we cannot paint a single painting.
        return 0;
    }
    int painted = 0;

    // Loop through every ninja and count their contribution.
    for (int i = 0; i < n; i++) {

        // Declare 'fullSpeed' to store the number of times ninja will work at 'fullSpeed'.
        // Variable 'halfSpeed' will only be used when the number of shifts is odd.

        long long fullSpeed = 0, halfSpeed = 0;
        if (numberofShifts % 2 == 0) {
            fullSpeed = numberofShifts / 2;
            halfSpeed = 1;
        }
        else {
            fullSpeed = (numberofShifts + 1) / 2;
        }

        long long comp = fullSpeed * a[i] + halfSpeed * (a[i] / 2);
        if (fullSpeed > 1 && a[i] % 2) {
            // We must subtract 1 from all fullSpeed counts except the first.
            // Because if the initial speed is odd, even if we rest for a shift, we won't get the same speed.
            // 'a[i]' = 5; after working speed will be 2. And after resting speed is 4, it cannot be 5.
            comp -= fullSpeed - 1;
        }
        if (comp >= m) {
            // If we can paint more of the 'm' painting; return true.
            // Returning in between to avoid overflow.
            return true;
        }
        painted += comp;
        if (painted >= m) {
            return true;
        }
    }
    return false;
}

long long minTimeRequired(int n, int m, int k, vector<int> &a) {

    // Declare 'l' and 'r' to represent search space of our binary search.
    long long l = 1LL, r = LLONG_MAX;
    int cnt = 0;

    // Check if the paintings are impossible to paint.
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) {
            // Even if one ninja has 'a[i] > 1' we can paint all the paintings.
            cnt = -1; break;
        }
        else {
            cnt++;
        }

    }
    // If all paintings can't be painted.
    if (cnt > -1 && cnt < m) {
        return -1LL;
    }

    // Perform binary search.
    while (r - l > 1) {
        long long mid = (l + (r - l) / 2);
        if (canPaint(mid, m, k, a)) {
            // If we can paint in 'mid' seconds, move 'r' to 'mid'.
            r = mid;
        }
        else {
            // Otherwise, increase 'l' to 'mid'.
            l = mid;
        }
    }

    // Now, 'r-l' = 1. If we can paint in 'l' seconds return 'l', otherwise return 'r'.
    if (canPaint(l, m, k, a)) {
        return l;
    }
    return r;
}