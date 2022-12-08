#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    // Write your code here
    long long int i = 0, j= 0, n1 = a.length(), n2 = b.length(), num1 = 0, num2 = 0;
    while(i < n1 || j < n2)
    {
        while(i < n1 && a[i] != '.')
        {
            num1 = num1*10 + (a[i] - '0');
            ++i;
        }
        while(j < n2 && b[j] != '.')
        {
            num2 = num2 * 10 + (b[j] - '0');
            ++j;
        }
        if(num1 > num2)
            return 1;
        if(num1 < num2)
            return -1;
        ++i, ++j; 
        num1 = 0, num2 = 0;
    }
    return 0;
}