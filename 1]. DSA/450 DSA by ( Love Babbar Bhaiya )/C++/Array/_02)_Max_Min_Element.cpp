#include <iostream>
using namespace std;

struct Pair 
{
    int min, max;
};

struct Pair getMinMax(int arr[], int low, int high)
{
    struct Pair minmax, minmaxLeft, minmaxRight;
    int mid;
    
    if(low == high)
    {
        minmax.min = arr[low];
        minmax.max = arr[high];
        return minmax;
    }
    
    if(high == low+1)
    {
        if(arr[low] < arr[high])
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        else
        {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
        return minmax;
    }
    
    mid = (low+high)/2;
    minmaxLeft = getMinMax(arr, low, mid);
    minmaxRight = getMinMax(arr, mid+1, high);
    
    if(minmaxLeft.min < minmaxRight.min)
        minmax.min = minmaxLeft.min;
    else
        minmax.min = minmaxRight.min;
    
    if(minmaxLeft.max > minmaxRight.max)
        minmax.max = minmaxLeft.max;
    else
        minmax.max = minmaxRight.max;
        
    return minmax;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 9}, arr_size = 6;
    struct Pair minmax = getMinMax(arr, 0, arr_size-1);
    cout<<"Minimum Element: "<<minmax.min<<endl;
    cout<<"Maximum Element: "<<minmax.max;
	return 0;
}