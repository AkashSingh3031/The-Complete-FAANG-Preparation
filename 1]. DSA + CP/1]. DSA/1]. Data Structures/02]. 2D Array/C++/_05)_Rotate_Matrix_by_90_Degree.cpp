#include<iostream>
using namespace std;

const int R=4, C=4, n=4;
void rotate90(int mat[R][C])
{
    int temp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[n-j-1][i] = mat[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat[i][j] = temp[i][j];

    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
}

int main()
{
    cout<<"90 deg Rotated Matrix = \n";
    int mat[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    
    rotate90(mat);
    cout<<endl;
}