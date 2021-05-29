#include<iostream>
using namespace std;

int subArraySum(int arr[], int n, int given_sum)
{
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            if(sum == given_sum)
            {
                cout<<"Sum found between indexes "<< i <<" and "<< j <<endl;
                return true;
            }
        }
    }
    cout<<"No subArray found"<<endl;
}

int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5}, n=6, given_sum=23;
    subArraySum(arr, n, given_sum);
}
