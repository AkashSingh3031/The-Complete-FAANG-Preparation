#include <bits/stdc++.h>  
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long double lld;
typedef pair<int,int>pii;
#define f first
#define s second
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
template<typename T>
class UnionFind{
public:
    unordered_map<T, T> uf;
    unordered_map<T, int> size;
    int longest = 0;
    UnionFind(){}
    
    void insert(T a)
    {
        if (uf.count(a) == 0)
        {
            uf[a] = a;
            size[a] = 1;
        }

    }
    T root(T i) 
    {
        while(i != uf[i])
        {
            i = uf[i];
            uf[i] = uf[uf[i]];
        }
        return i;
    }

    
    int merge(T p, T q)
    {
        T a = root(p);
        T b = root(q);
       
        
        if (a == b)
            return size[a];
        if (size[a] < size[b])
        {
            uf[a] = b;
            size[b] += size[a];
            
            return size[b];
        }
        else
        {
                uf[b] = a;
                size[a] += size[b];
            
                return size[a];
        }
    }
};

class Solution {
UnionFind<int>uf;
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>seen;
        if (nums.size() == 0)
            return 0;
        int longe = 1;
        for (auto &a: nums)
        {
            uf.insert(a);
            seen.insert(a);
            if (seen.count(a-1))
                longe = max(longe, uf.merge(a, a-1));
            if(seen.count(a+1))
               longe = max(longe, uf.merge(a, a+1));
        }
        return longe;
        
    }
};