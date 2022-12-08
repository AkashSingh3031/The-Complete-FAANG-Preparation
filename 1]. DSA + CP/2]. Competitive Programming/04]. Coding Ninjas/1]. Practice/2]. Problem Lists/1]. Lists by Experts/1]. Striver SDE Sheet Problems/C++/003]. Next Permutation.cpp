#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int l, r; // 'l' is pivot and 'r' is rightmost successor
    // find decreasing sequence
    for(l=n-2; l>=0; l--) 
        if(permutation[l] < permutation[l+1])
            break;
    // if all number in sequence in decreasing order
    if(l<0)
        reverse(permutation.begin(), permutation.end());
    else 
    {
        // find rightmost successor, which greater than pivot number
        for(r=n-1; r>l; r--) 
            if(permutation[r] > permutation[l])
                break;
        swap(permutation[l], permutation[r]);
        // reverse the decreasing sequence after swaping pivot number and rightmost successor
        reverse(permutation.begin()+l+1, permutation.end());
    }
    return permutation;
}
