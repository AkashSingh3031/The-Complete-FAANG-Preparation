#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& a, int n)
{   
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
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

    bubbleSort(arr,n);

    for(auto &i : arr)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}