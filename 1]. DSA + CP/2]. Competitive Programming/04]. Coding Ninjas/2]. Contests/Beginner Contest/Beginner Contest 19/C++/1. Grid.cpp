/*
    Time Complexity : O(1)
    Space Complexity : O(1)
*/
#include<iostream>    
using namespace std;
int maximumGrid(int n, int m, int a, int b, int c, int d) {

    //If 'C' < 'A' or 'D' < 'B'.
    if(c < a || d < b) {
        return -1;
    }

    // Return 'C + D - A - B'. 
    return c + d - a - b;
}