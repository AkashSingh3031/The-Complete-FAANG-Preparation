#include<iostream>
using namespace std;

const int R=4, C=4;
void printSpiral(int mat[R][C], int R, int C)
{
    int top=0, left=0, bottom=R-1, right=C-1;
    while(top <= bottom && left <= right)
    {
        for(int i=left; i<=right; i++)
            cout<<mat[top][i]<<" ";
            cout<<endl;
        top++;

        for(int i=top; i<=bottom; i++)
            cout<<mat[i][right]<<" ";
            cout<<endl;
        right--;

        if(top <= bottom)
        {
            for(int i=right; i>=left; i--)
            cout<<mat[bottom][i]<<" ";
            cout<<endl;
        bottom--;
        }

        if(left <= right)
        {
            for(int i=bottom; i>=top; i--)
            cout<<mat[i][left]<<" ";
            cout<<endl;
        left++;
        }
    }
}

int main()
{
    cout<<"Spiral Matrix Traversal = \n";
    int R=4, C=4;
    int mat[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    
    printSpiral(mat, R, C);
    cout<<endl;
}