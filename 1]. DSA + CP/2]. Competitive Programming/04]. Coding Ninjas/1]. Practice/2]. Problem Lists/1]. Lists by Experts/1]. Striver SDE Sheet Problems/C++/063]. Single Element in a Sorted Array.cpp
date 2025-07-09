#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int xr{};
    for(auto num: arr)
        xr = xr^num;
    return xr;
}
