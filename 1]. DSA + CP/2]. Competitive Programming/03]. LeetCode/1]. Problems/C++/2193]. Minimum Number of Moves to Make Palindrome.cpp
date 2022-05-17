class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        deque<int> v[26];
        int index = 0;
        for(auto it : s) {
            v[it - 'a'].push_back(index++);
        }
        int vis[2005];
        fill(vis, vis + 2005, 0);
        int l = 0, r = s.size() - 1;
        int ans = 0;
        while(l < r) {
            int Min = 1e9, Mini = 0;
            for(int i = 0; i < 26; i++) {
                if(v[i].size() >= 2) {
                    int sum = 0;
                    int a = v[i].front();
                    int b = v[i].back();
                    for(int i = 0;i < a; i++) {
                        if(!vis[i]) sum++;
                    }
                    for(int i = s.size() - 1; i > b; i--) {
                        if(!vis[i]) sum++;
                    }
                    if(sum < Min){
                        Min = sum;
                        Mini = i;
                    }
                }
            }
            ans += Min;
            int a = v[Mini].front();
            v[Mini].pop_front();
            int b = v[Mini].back();
            v[Mini].pop_back();
            vis[a] = vis[b] = 1;
            l++;
            r--;
        }
        return ans;
    }
};
