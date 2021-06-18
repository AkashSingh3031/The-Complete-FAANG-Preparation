#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        multiset<int>X;
        multiset<int>Y;
        for(int i=0;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            x.push_back({a,b});
            y.push_back({b,a});
            X.insert(a);
            Y.insert(b);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int height1=0;
        int height2=0;
        int h1Max=0;
        int h1Min=LONG_MAX;
        int area=LONG_MAX;
        for(int i=0;i<n-1;++i){
            h1Max=max(h1Max,x[i].second);
            h1Min=min(h1Min,x[i].second);
            height1=h1Max-h1Min;
            auto it=Y.find(x[i].second);
            Y.erase(it);
            height2=*Y.rbegin()-*Y.begin();
            int newArea=(x[i].first-x[0].first)*height1+(x[n-1].first-x[i+1].first)*height2;
            area=min(area,newArea);
        }
        int width1=0;
        int width2=0;
        int w1Max=0;
        int w1Min=LONG_MAX;
        for(int i=0;i<n-1;++i){
            w1Max=max(w1Max,y[i].second);
            w1Min=min(w1Min,y[i].second);
            width1=w1Max-w1Min;
            auto it=X.find(y[i].second);
            X.erase(it);
            width2=*X.rbegin()-*X.begin();
            int newArea=(y[i].first-y[0].first)*width1+(y[n-1].first-y[i+1].first)*width2;
            area=min(area,newArea);
        }
        
        
        if(area==LONG_MAX)
        area=0;
        cout<<area<<endl;
        }
    return 0;
}