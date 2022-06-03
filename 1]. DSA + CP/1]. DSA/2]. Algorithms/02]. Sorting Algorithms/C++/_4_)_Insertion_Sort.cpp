#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &a){
    int i,j;
    for(i=1;i<n;i++){
       int temp = a[i];
       for(j=i-1;j>=0;j--){
           if(a[j]>temp){
               a[j+1]=a[j];
           }else break;        
       }
       a[j+1]=temp;
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

    insertionSort(n,arr);

    for(auto &i : arr)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}