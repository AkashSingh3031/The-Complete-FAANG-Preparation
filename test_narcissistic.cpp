#include <cmath>
#include <iostream>
using namespace std;

// Test the fixed Narcissistic Number logic (without pow)
bool isNarcissistic(int num) {
    int original = num;
    int digitCount = 0;
    int temp = num;
    
    // Count digits
    while (temp > 0) {
        digitCount++;
        temp /= 10;
    }
    
    int sum = 0;
    temp = num;
    
    // Calculate sum without using pow()
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digitCount; i++) {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    
    return sum == original;
}

int main() {
    cout << "Testing Narcissistic Number function:" << endl;
    
    // Test cases
    int testCases[] = {153, 371, 407, 9474, 123, 1634};
    bool expected[] = {true, true, true, true, false, true};
    
    for (int i = 0; i < 6; i++) {
        bool result = isNarcissistic(testCases[i]);
        cout << testCases[i] << " is " << (result ? "" : "NOT ") << "narcissistic";
        cout << " (expected: " << (expected[i] ? "true" : "false") << ")";
        cout << " ✅" << (result == expected[i] ? " PASS" : " FAIL") << endl;
    }
    
    return 0;
}
