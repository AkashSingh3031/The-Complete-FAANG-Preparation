#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d){
    if(a>b){
        if(a>c){
            if(a>d)
                return a;
            else
                return d;
        }
        else
            return c;
    }
    else{
        if(b>c){
            if(b>d)
                return b;
            else
                return d;
        }
        else{
            if(c>d)
                return c;
            else
                return d;
        }
    }
}

int main() {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans = max_of_four(a, b, c, d);
    cout<<ans;
    
    return 0;
}
