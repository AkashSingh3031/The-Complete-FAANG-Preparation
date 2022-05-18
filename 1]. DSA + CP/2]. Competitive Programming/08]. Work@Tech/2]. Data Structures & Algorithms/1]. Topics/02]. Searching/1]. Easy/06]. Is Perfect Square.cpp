/*
Example:
    isPerfectSquare(25) => true
    isPerfectSquare(30) => false
*/

bool searchRoot(int low, int high, int num) {
   	if (high >= low) {
       	int mid = (high + low) / 2;
       	int square = mid * mid;
       	if (square == num) {
           	return true;
       	} 
		else if (square > num) {
           	return searchRoot(low, mid - 1, num);
       	} 
		else {
           	return searchRoot(mid + 1, high, num);
       	}
   	}
   	return false;
}

bool isPerfectSquare(int num) {
   	int maxVal = 10000; // To avoid overflow while computing square
   	return searchRoot(1, maxVal, num);
}