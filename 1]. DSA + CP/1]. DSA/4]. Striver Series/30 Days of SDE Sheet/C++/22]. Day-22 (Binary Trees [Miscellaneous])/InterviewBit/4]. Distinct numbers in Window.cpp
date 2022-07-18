vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> m;
    vector<int> v;
    for(int i = 0;i<B;i++){
        m[A[i]]++;
    }
    v.push_back(m.size());
   
    for(int i = B;i<A.size();i++){
       
        m[A[i-B]]--;
   
        if( m[A[i-B]] == 0) {
         
            m.erase( A[i-B]);
           
        }
        m[A[i]]++;
        v.push_back(m.size());
    }
   
    return v;
}
