int Solution::solve(string A) {
    string input = A + "@";
    reverse(A.begin(),A.end());
    input += A;
    int n = input.size();
    vector<int>lps(n);
    lps[0] = 0;
    for(int i = 1 ; i < n ; ++i){
        int x = lps[i-1];
        while(input[x] != input[i]){
            if(x == 0){
                x = -1;
                break;
            }
            x = lps[x-1];
        }
        lps[i] = x + 1;
    }
    return A.size() - lps[n-1];
}
