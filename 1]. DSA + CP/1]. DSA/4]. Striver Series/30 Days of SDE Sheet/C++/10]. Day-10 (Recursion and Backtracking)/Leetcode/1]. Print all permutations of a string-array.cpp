class Solution {
public:
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
    
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
};