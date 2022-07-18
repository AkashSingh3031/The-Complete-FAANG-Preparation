long getTrappedWater(long *a, int n){
    // Write your code here.
    long l = 0, r = n-1, level = 0, water = 0;
    while (l < r) {
        long lower = a[a[l] < a[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}