string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int>arr;
    string ans="";
    int fact=1;
    
    for(int i=1;i<n;i++){
        fact=fact*i;
        arr.push_back(i);
    }
    arr.push_back(n);
    k=k-1;
    
    while(true){
        ans=ans+to_string(arr[k/fact]);
        arr.erase(arr.begin()+k/fact);
        if(arr.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/arr.size();
    }
    return ans;
}
