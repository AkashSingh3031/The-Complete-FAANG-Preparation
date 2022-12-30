vector<int> twoSum(vector<int>& A, int target) {
    
     vector<int> ans;
        unordered_map<int,int> mymap;
        
        for(int i=0; i<A.size(); i++){
            int search = target - A[i];
            
            if(mymap.find(search)==mymap.end()){
                mymap[A[i]] = i;
            }else{
                 ans.push_back(mymap[search]);
                 ans.push_back(i);
                 return ans;
              }
        }  
            
        return ans;
        
    }
 
