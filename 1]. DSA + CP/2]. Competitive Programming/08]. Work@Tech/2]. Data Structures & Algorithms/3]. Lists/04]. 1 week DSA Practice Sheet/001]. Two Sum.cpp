/*
Example
    A: [1, 3, 3, 4]
    target: 5
    Answer: [0, 3]
    
Sample Input
  2
  6
  8 2 10 4 1 3
  9
  5
  2 4 2 3 2
  7
Expected Output
  0 4
  1 3 
*/

pair<int,int> twoSum(vector<int> &A, int target) {
    // add your logic here
	unordered_map<int, int> hash;
	for(int i=0; i<A.size(); i++) {
		if(hash.find(target-A[i]) != hash.end())
			return {hash[target-A[i]], i};
		hash[A[i]] = i;
	}
	return {};
}
