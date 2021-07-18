 void convertToWave(vector<int>& arr, int n){
        
        // Your code here
        int i;
        for(i=0;i<n-1;i=i+2)
        {
            swap(arr[i],arr[i+1]);
        }
    }