/*
    Time complexity: O(N) 
    Space complexity: O(1)
    Where 'N' is the number of Levels in Fracture.
*/
#include <vector>
using namespace std;

int MaxLevels(int n, int f, vector<int>&A){

	/*Initialize two pointers pointing to the first element of A.*/
	int first_pointer = 0;
	int second_pointer = 0;

	// Intialize variable 'sm' to store sm of the window.
	int sm = 0;

	// Initialize variable to store result as 0 since 0 is the least possible answer.
	int res = 0;
	
	// Move first pointer 
	while(first_pointer < n){

		//Move second pointer as long as the total sm is less than free time.
		while( (second_pointer < n) && (sm + A[second_pointer] <= f) ){
			sm+=A[second_pointer]; 
			++second_pointer;
		}

		/* Once the second pointer is as far as it can go the first pointer,
		decrement the element at first pointer from the sum and increment
		the first pointer. */

		res = max(res, second_pointer-first_pointer);

		sm-=A[first_pointer];

		first_pointer++;
	}

	// Return the result.
	return res;
}
