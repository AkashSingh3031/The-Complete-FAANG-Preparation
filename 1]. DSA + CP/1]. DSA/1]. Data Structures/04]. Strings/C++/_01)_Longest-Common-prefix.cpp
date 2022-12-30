string longestCommonPrefix(vector<string>& strs) {
        
        //for string the final answer
        string ans = "";
        
        if(strs.size() == 0)
            return "";
        
        //It will return the minimum element
        string s = *min_element(strs.begin(), strs.end());
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<strs.size(); j++){
                if(s[i] != strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(s[i]);
        }
        
          return ans;     
    }