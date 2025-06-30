#include <vector>
#include <iostream>
using namespace std;

vector<int> getCumulativeSum(vector<int> &arr) {
   vector<int> cumulativeSum(arr.size());
   cumulativeSum[0] = arr[0];
   for (int i = 1; i < arr.size(); i++) {
       cumulativeSum[i] = cumulativeSum[i - 1] + arr[i];
   }
   return cumulativeSum;
}

int main() {
    // Test case 1: [1, 2, 3, 4] -> [1, 3, 6, 10]
    vector<int> test1 = {1, 2, 3, 4};
    vector<int> result1 = getCumulativeSum(test1);
    
    cout << "Test 1 - Input: [1, 2, 3, 4]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Expected: [1, 3, 6, 10]" << endl;
    
    // Test case 2: [1, 1, 1, 1, 1] -> [1, 2, 3, 4, 5]
    vector<int> test2 = {1, 1, 1, 1, 1};
    vector<int> result2 = getCumulativeSum(test2);
    
    cout << "\nTest 2 - Input: [1, 1, 1, 1, 1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Expected: [1, 2, 3, 4, 5]" << endl;
    
    return 0;
}
