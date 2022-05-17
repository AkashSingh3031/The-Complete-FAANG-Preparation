 
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{   
    int n ,i, x= 0 ;
    string input;

	cin >> n ;
    while(n--){
        cin >> input;
        if(input[0] == '+' || input[1]== '+'){
            x++;
        }
        if(input[0] == '-' || input[1]== '-'){
            x--;
        }
    }
    cout << x ;
}
