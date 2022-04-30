#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n ,sol ,vote , input = 0;
    cin >> n;
    while (n > 0){
        for(int i = 0 ; i <3 ;i++){
            cin>>input;
            vote = vote + input;
        }
        if(vote >= 2){
            sol ++;
        }
        n--;
        vote = 0 ;
    }
    cout<<sol;
}
