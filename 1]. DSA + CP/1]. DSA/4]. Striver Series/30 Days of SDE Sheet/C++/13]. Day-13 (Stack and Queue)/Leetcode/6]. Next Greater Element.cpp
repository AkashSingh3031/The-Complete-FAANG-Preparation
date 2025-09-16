#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) 
            ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};
