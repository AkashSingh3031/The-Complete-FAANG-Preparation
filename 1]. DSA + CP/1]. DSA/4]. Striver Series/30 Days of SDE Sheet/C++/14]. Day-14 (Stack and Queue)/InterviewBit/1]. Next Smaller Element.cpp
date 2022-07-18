vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    reverse(A.begin(), A.end());
    stack <int> stackk;
    stackk.push(-1);
    vector <int> answer(n);
    for(int i=n-1 ; i>=0 ; i--)
    {
        int value_of_array = A[i];
        while(stackk.top()>=value_of_array){
            stackk.pop();
        }
        answer[i] = stackk.top();
        stackk.push(value_of_array);
    }
    reverse(answer.begin(), answer.end());
    return answer ;
}
