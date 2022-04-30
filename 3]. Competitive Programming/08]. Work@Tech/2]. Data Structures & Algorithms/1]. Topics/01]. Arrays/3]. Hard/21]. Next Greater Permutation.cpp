/*
Example
    Array: [1, 2, 3, 4]

    Next Greater Permutation: [1, 2, 4, 3]
    Next Greater Permutation: [1, 3, 2, 4]
    Next Greater Permutation: [1, 3, 4, 2]
    Next Greater Permutation: [1, 4, 2, 3]
    Next Greater Permutation: [1, 4, 3, 2]
    Next Greater Permutation: [2, 1, 3, 4]
*/

void nextGreaterPermutation(vector<int> &nums) {
    // add your logic here
	if(nums.size() == 1) 
		return;
    
	int i = nums.size()-2,j = i+1;
    while(i >= 0 && nums[i] >= nums[i+1] ) 
		i--;
	
    if(i >= 0){
        while(i>= 0 && nums[i] >= nums[j]) 
			j--;
        swap(nums[i],nums[j]);
    }
	
    reverse(nums.begin()+i+1,nums.end());
}