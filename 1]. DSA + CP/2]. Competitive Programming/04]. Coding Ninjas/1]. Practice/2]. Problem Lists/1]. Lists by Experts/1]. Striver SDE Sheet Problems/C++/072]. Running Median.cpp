#include<bits/stdc++.h>
class MedianFinder {
public:
     multiset<int> nums;
     multiset<int>::iterator it = nums.begin();
     bool is_even = true;
    
    MedianFinder() { }
    
    void addNum(int num) 
    {
        nums.insert(num);
        is_even = !is_even;
        if (it == nums.end() || (is_even && (*it) <= num)) it++;
        if (!is_even && (*it) > num) it--;
    }
    
    int findMedian() 
    {
         return (!is_even)? *it : (*it + *prev(it)) / 2;
    }
};
void findMedian(int *arr, int n)
{
    MedianFinder* obj = new MedianFinder();
    for(int i=0;i<n;i++)
    {
        obj->addNum(arr[i]);
        cout<<obj->findMedian()<<" ";
    }
}