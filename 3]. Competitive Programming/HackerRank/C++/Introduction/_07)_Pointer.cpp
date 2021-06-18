#include<cstdlib>
#include<iostream>
using namespace std;

void update(int *a,int *b) {
    // Complete this function    
    int sum,diff;
    sum= *a + *b;
    diff= *a - *b;
    *a = sum;
    *b = abs(diff);
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    cin>>a>>b;
    update(pa, pb);
    cout<<a<<endl<<b;
    
    return 0;
}

