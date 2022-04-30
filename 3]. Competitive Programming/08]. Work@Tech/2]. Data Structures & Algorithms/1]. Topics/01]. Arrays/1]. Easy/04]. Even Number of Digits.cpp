/*
Example:
    Array: [42, 564, 5775, 34, 123, 454, 1, 5, 45, 3556, 23442]
    Answer: 42, 5775, 34, 45, 3556
*/

int getDigitCount(int n) {
    int count = 0;
    if(n == 0) {
        return 1;
    }
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

vector<int> getEvenDigitNumbers(vector<int> &arr) {
    vector<int> evenDigitList;
    for (int x: arr) {
        if(getDigitCount(x) % 2 == 0) {
            evenDigitList.push_back(x);
        }
    }
    return evenDigitList;
}