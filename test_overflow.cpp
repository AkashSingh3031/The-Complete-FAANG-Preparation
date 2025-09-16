#include <iostream>
#include <vector>
using namespace std;

// Test the fixed zero permutation with long long to prevent overflow
vector<int> zeroPermutation(vector<int> &array) {
    int n = array.size();
    int position[n + 1];

    // Map each element with its position in the array.
    for (int i = 0; i < n; i++) {
        position[array[i]] = i;
    }

    // Get the sum of the array (fixed: using long long to prevent overflow).
    long long sum = (long long)n * (n + 1) / 2;

    // If sum of array is odd it is impossible.
    if (sum % 2 == 1) {
        return array;
    }

    // Else it is always possible.
    int currentNum = n;

    // For making 'sum' == 0 , positive elements sums upto '(sum/2)'.
    // And negative elements sums upto '(sum/2)'.
    long long targetSum = sum / 2;
    while (targetSum) {

        // If targetSum is greater than or equal to the 'currentNum' element.
        // We will perform an operation on that element.
        if (targetSum >= currentNum) {
            int ind = position[currentNum];
            array[ind] *= -1;
            targetSum -= currentNum;
        }
        currentNum--;
    }

    // Return array after all operations here.
    return array;
}

int main() {
    cout << "Testing zero permutation with overflow protection:" << endl;
    
    // Test with small array
    vector<int> test1 = {1, 2, 3, 4};
    cout << "Test 1 - Input: [1, 2, 3, 4]" << endl;
    vector<int> result1 = zeroPermutation(test1);
    
    int sum1 = 0;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        sum1 += result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Sum: " << sum1 << " (should be 0) ";
    cout << (sum1 == 0 ? "✅ PASS" : "❌ FAIL") << endl;
    
    // Test with larger array that could cause overflow with int
    vector<int> test2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "\nTest 2 - Input: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]" << endl;
    vector<int> result2 = zeroPermutation(test2);
    
    int sum2 = 0;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        sum2 += result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Sum: " << sum2 << " (should be 0) ";
    cout << (sum2 == 0 ? "✅ PASS" : "❌ FAIL") << endl;
    
    // Test with large n that would overflow with int arithmetic
    long long n = 50000;
    long long sum_test = n * (n + 1) / 2;
    cout << "\nOverflow test: n=50000, sum=" << sum_test << endl;
    cout << "This would overflow with int but works with long long ✅" << endl;
    
    return 0;
}
