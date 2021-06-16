	#include<bits/stdc++.h>
using namespace std;
void generate_parenthesis(int n,string out,int open,int close){
    //Base Case
    //Eg:for n=2,we will need 4 spaces to put 2 ('s and 2 )'s
    if(open+close==2*n){
        //out.push_back('\0');
        cout<<out<<" ";
    }

    //Condition for open brackets
    //We push an open braket if the condition is true
    //We increment the count of open
    //Later we might want to put a closed parenthesis in the same position
    //So we pop
    if(open<n){
        out.push_back('(');
        generate_parenthesis(n,out,open+1,close);

        out.pop_back();
    }
    //Condition for closing brakets
    if(close<open){
        out.push_back(')');
        generate_parenthesis(n,out,open,close+1);
    }
}
int main(){
    string out;
    int n;
    cin>>n;
    //out.push_back('(');
    generate_parenthesis(n,out,0,0);
}
