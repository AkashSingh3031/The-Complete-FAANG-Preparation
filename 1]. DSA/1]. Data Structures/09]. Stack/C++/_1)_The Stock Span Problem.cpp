#include<bits/stdc++.h>
using namespace std;
void stock_span(int input[],int n,int span[]){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=0;i<n;i++){
        int current_price=input[i];
        while(!s.empty() && input[s.top()]<=current_price){
            s.pop();
        }

        if(!s.empty()){
            int pre_highest=s.top();
            span[i]=i-pre_highest;
        }
        else
            span[i]=i+1;
        s.push(i);
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int span[n];
    stock_span(input,n,span);
    for(int i=0;i<n;i++)
        cout<<span[i]<<" ";
}
