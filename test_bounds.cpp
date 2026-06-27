#include <iostream>
#include <vector>
using namespace std;

// Test the fixed binary search with bounds checking
int binarySearch(vector<int> arr, int low, int high) {
    if (high > low) {
        int mid = (high + low) / 2;
        
        if (mid + 1 < arr.size() && arr[mid] < 0 && arr[mid + 1] >= 0) {
            return mid;
        } 
        else if (mid + 1 < arr.size() && arr[mid] >= 0 && arr[mid + 1] >= 0) {
            return binarySearch(arr, 0, mid);
        } 
        else {
            return binarySearch(arr, mid + 1, high);
        }
    }
    return -1;
}

int getNegativeNumbersCount(vector<int> &arr) {
    if (arr[0] >= 0) {
        return 0;
    }
    if (arr[arr.size()-1] < 0) {
        return arr.size();
    }
    return binarySearch(arr, 0, arr.size() - 1) + 1; //index + 1
}

int main() {
    cout << "Testing negative numbers count with bounds checking:" << endl;
    
    // Test case 1: [-5, -3, -2, 3, 4, 6, 7, 8] -> 3
    vector<int> test1 = {-5, -3, -2, 3, 4, 6, 7, 8};
    int result1 = getNegativeNumbersCount(test1);
    cout << "Test 1: Count = " << result1 << " (expected: 3) ";
    cout << (result1 == 3 ? "✅ PASS" : "❌ FAIL") << endl;
    
    // Test case 2: [0, 1, 2, 3, 4, 6, 7, 8] -> 0
    vector<int> test2 = {0, 1, 2, 3, 4, 6, 7, 8};
    int result2 = getNegativeNumbersCount(test2);
    cout << "Test 2: Count = " << result2 << " (expected: 0) ";
    cout << (result2 == 0 ? "✅ PASS" : "❌ FAIL") << endl;
    
    // Test case 3: [-1, -2, -3, -4] -> 4
    vector<int> test3 = {-1, -2, -3, -4};
    int result3 = getNegativeNumbersCount(test3);
    cout << "Test 3: Count = " << result3 << " (expected: 4) ";
    cout << (result3 == 4 ? "✅ PASS" : "❌ FAIL") << endl;
    
    // Edge case: single element arrays
    vector<int> test4 = {-1};
    int result4 = getNegativeNumbersCount(test4);
    cout << "Test 4 (edge): Count = " << result4 << " (expected: 1) ";
    cout << (result4 == 1 ? "✅ PASS" : "❌ FAIL") << endl;
    
    return 0;
}
