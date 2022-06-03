#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
     for(int i=0;i<n-1;i++){
         int minIndex = i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minIndex])
                    minIndex = j;
            }
          swap(arr[minIndex],arr[i]);
        }
}



int main(){
    int n;
    cin>>n;
    int a;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }

    selectionSort(arr,n);

    for(auto &i : arr)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}