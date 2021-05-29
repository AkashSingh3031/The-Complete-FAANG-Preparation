#include<iostream>
using namespace std;

int subArraySum(int arr[], int n, int given_sum)
{
    int curr_sum = arr[0], start=0;
    for(int end=1; end<n; end++)
    {
        while(curr_sum > given_sum && start < end-1)
        {
            curr_sum -= arr[start];
            start++;
        }
        if(curr_sum == given_sum)
        {
            cout<<"Sum found between indexes "<< start <<" and "<< end-1 <<endl;
            return true;
        }
        if(end<n)
            curr_sum += arr[end];
    }
    cout<<"No subArray found"<<endl;
}

int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5}, n=6, given_sum=23;
    subArraySum(arr, n, given_sum);
}
