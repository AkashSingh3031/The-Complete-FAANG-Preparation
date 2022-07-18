#include<bits/stdc++.h>
class Kthlargest {
public:
   priority_queue<int,vector<int>,greater<int>>q;
    int size;
    Kthlargest(int k, vector<int> &arr)     
    {
        size=k;
        for(int i=0;i<arr.size();i++)
        {
            q.push(arr[i]);
            if(q.size()>k)
            {
                q.pop();
            }
        }
    }

    void add(int num) {
        q.push(num);
        if(q.size()>size)
        {
            q.pop();
        }
    }

    int getKthLargest() {
      int a= q.top();
     
        return a;
    }

};