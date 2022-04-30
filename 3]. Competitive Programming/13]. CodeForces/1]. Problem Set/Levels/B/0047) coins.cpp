#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int a , b , c =0;
void print(){
 if(a == b || a == c || b == c) cout << "Impossible\n";
    else if(a == 2 && b == 1 && c==0)  
        cout << "CBA\n";

    else if(a == 2 && b == 0 && c==1)  
        cout << "BCA\n";
    
    else if(a == 1 && b == 2 && c==0)  
        cout << "CAB\n";
    
    else if(a ==1 && b == 0 && c==2)  
        cout << "BAC\n";
    
    else if(a == 0 && b == 1 && c==2)  
        cout << "ABC\n";
    
    else if(a ==0 && b == 2 && c==1)  
        cout << "ACB\n";
}
void solve(string input){
    if(input[1] == '>'){
        if(input[0] == 'A') a++;
            else if(input[0] == 'B') b++;
                else c++;
    }else{
        if(input[2] == 'A') a++;
            else if(input[2] == 'B') b++;
                else c++;
    }
}
int main()
{   
    int n = 3;
	string input;
    while(n--){
        cin>>input;
        solve(input);
    }
    print();

}
