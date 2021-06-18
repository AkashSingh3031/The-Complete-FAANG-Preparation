#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<vector<int>> arr;
    int n,q;
    cin>>n>>q;

    for(int i=0; i<n ; i++){
        int e;
        cin>>e;
        vector<int> temp;
        for(int j=0; j < e; j++){
            int ele;
            cin>>ele;
            temp.push_back(ele);
        }
        arr.push_back(temp);
    }

    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<arr[x][y]<<endl;
        
    }


    return 0;
}
