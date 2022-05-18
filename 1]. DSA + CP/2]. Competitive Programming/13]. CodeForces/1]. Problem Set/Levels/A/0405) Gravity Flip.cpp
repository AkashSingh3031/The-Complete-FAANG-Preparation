 
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{   
    int n,a = 0 ;
    cin >> n ;
    vector<int> output(n,0);
    while(n--){
        cin>>output[n];
    }
    sort(output.begin(),output.end());
    for (int i: output)
    std::cout << i << ' ';
}
