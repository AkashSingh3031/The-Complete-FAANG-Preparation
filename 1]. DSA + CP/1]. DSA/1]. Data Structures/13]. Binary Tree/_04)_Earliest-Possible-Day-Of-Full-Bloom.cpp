<<<<<<< HEAD
class Solution {
public:
 
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<int> id(plantTime.size());
        
        iota(id.begin(), id.end(), 0);
        
        sort(id.begin(), id.end(), [&](int i, int j){return growTime[i] > growTime[j]; });
        
        int ans = 0, day = 0;
        for (int i : id) {
            day += plantTime[i];
            ans = max(ans, day + growTime[i]);
        }
        return ans;
    }


     //........................> Approach - 02 <.....................
/*

    static bool comp(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({plantTime[i],growTime[i]});
        }
        
        sort(v.begin(),v.end(),comp);
        int start = 0;
        int ans = 0;
        
        for(int i=0; i<plantTime.size(); i++){
            start = start + v[i].first;
            ans = max(ans,start+v[i].second);
        }
        
        return ans;
    
    }
};

=======
class Solution {
public:
 
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<int> id(plantTime.size());
        
        iota(id.begin(), id.end(), 0);
        
        sort(id.begin(), id.end(), [&](int i, int j){return growTime[i] > growTime[j]; });
        
        int ans = 0, day = 0;
        for (int i : id) {
            day += plantTime[i];
            ans = max(ans, day + growTime[i]);
        }
        return ans;
    }


     //........................> Approach - 02 <.....................
/*

    static bool comp(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({plantTime[i],growTime[i]});
        }
        
        sort(v.begin(),v.end(),comp);
        int start = 0;
        int ans = 0;
        
        for(int i=0; i<plantTime.size(); i++){
            start = start + v[i].first;
            ans = max(ans,start+v[i].second);
        }
        
        return ans;
    
    }
};

>>>>>>> 933109f66b02b03bd431ec88c38910f29a5c9b22
*/