int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int total = 0;
    int res = 0;
        
    for(auto n : arr) {
        if(n == 1) {
            total++;
            res = max(res, total);
        } 
        else {
            total = 0;
        }
    }
    return res;
}
