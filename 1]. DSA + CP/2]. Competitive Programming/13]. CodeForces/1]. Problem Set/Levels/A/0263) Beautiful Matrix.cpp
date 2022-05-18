 
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{   
    int temp= 0 ;
    int i_one , j_one,move = 0;
    for(int i=0; i<=4; i++){ 
        for(int j=0; j<=4; j++){
            cin>>temp;
            if(temp == 1){
                i_one = i;
                j_one = j;
            } 
        }
    }
    if(i_one != 2 || j_one !=2){
        move = abs(i_one-2) + abs(j_one-2);
    }
    cout<<move;
}
