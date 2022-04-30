#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int a , b = 0;
    int count = 0;
    cin>>a>>b;
    while(a<=b){
        a = a*3;
        b = b*2;
        count++;
    }
    cout<<count;
}
