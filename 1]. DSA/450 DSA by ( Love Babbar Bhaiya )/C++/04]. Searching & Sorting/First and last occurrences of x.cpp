// First and last occurrences of x 
// Link : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Explanation: First occurrence of 5 is at index 2 and last
//              occurrence of 5 is at index 5. 
             
vector<int> find(int arr[], int n , int x )
{
    vector<int>v;
    int l=0,h=n-1;
    int focr=-1,locr=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==x){focr=mid;
        h=mid-1;}
        else if(arr[mid]>x){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    l=0,h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==x){locr=mid;
        l=mid+1;}
        else if(arr[mid]>x){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    v.push_back(focr);
    v.push_back(locr);
    return v;
}