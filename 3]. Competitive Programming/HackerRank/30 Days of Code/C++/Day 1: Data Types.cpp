#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int a;
    double b;
    string c;

    cin>>a>>b;
    getline(cin>>ws, c);

    cout<<(i+a)<<endl;
    cout<<fixed<<setprecision(1)<<(d+b)<<endl;
    cout<<(s+c);

    return 0;
}