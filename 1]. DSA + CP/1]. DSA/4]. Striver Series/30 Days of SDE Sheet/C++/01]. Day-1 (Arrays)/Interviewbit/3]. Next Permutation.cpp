vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size(), l, r; // 'l' is pivot and 'r' is rightmost successor
        
    // find decreasing sequence point
    for(l=n-2; l>=0; l--)
        if(A[l] < A[l+1])
            break;
    
    // if all number in sequence in decreasing order
    if(l<0)
        reverse(A.begin(), A.end());
    else {
        // find rightmost successor, which greater than pivot number
        for(r=n-1; r>l; r--)
            if(A[r] > A[l])
                break;
        swap(A[l], A[r]);
        // reverse the decreasing sequence after swaping pivot number and rightmost successor
        reverse(A.begin()+l+1, A.end());
    }
    return A;
}
