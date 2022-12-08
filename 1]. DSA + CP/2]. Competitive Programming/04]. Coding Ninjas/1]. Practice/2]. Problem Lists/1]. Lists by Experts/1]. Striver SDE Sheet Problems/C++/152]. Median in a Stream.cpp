#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>> minheap;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
 
        if(i%2==0)
        {
            minheap.push(arr[i]);
            maxheap.push(minheap.top());
            minheap.pop();
            vec.push_back(maxheap.top());
        }
        else
        {
            maxheap.push(arr[i]);
            minheap.push(maxheap.top());
            maxheap.pop();
            int num = (maxheap.top() + minheap.top())/2;
            vec.push_back(num);
        }
    }
    return vec;
}