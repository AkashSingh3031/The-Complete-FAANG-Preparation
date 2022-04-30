/*
Sample Input
    3            // Test Case Number
    5
    1
    12
Expected Output
    2 3 5

    2 3 5 7 11
*/

vector<int> primesUptoN(int n) {
    bool isPrime[n + 1];
   	for(int i = 2; i <= n; i++) {
       	isPrime[i] = true;
   	}
   
	isPrime[0] = isPrime[1] = false;
   	for(int i = 2; i * i <= n; i++) {
       	for(int j = i * i; j <= n; j += i) {
           	if(isPrime[i] == true) {
               	isPrime[j] = false;
           	}
       	}
   	}
   	
	vector<int> answer;
   	for(int i = 2; i <= n; i++) {
       	if(isPrime[i] == true) {
           	answer.push_back(i);
       	}
   	}
   	return answer;
}