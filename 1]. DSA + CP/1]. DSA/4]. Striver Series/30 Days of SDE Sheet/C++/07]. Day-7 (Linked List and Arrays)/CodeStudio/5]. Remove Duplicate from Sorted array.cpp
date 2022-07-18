int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    if(arr.size() == 0)
        return 0;
    int m = 1;
    for(int i =1; i < arr.size(); i++){
        if(arr[i] > arr[m-1]){
            arr[m] = arr[i];
            m++;
        }
    }
    return m;
}