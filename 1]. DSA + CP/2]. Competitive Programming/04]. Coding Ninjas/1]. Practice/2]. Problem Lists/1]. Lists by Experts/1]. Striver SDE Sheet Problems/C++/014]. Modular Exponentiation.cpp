#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    // Write your code here.
    long long res = 1, x1 = x;
    while(n) {
        if(n%2 != 0) {
            res = (res*x1%m)%m;
            n--;
        }
        else {
            x1 = (x1%m * x1%m)%m;
            n = n/2;
        }
    }
    return res%m;
}
