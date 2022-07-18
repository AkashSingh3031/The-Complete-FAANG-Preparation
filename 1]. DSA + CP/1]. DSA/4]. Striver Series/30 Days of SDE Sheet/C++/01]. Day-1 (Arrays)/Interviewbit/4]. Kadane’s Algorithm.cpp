int Solution::maxSubArray(const vector<int> &A) {
    int curr_sum = A[0], max_sum = A[0];
    for(int i=1; i<A.size(); i++)
    {
        curr_sum = max(A[i], curr_sum+A[i]);
        if(curr_sum > max_sum)
            max_sum = curr_sum;
    }
    return max_sum;
}
