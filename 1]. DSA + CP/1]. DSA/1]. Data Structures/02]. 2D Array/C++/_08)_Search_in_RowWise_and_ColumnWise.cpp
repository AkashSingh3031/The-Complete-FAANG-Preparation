#include<iostream>
using namespace std;

const int R=4, C=4;
void Row_Column_search(int mat[R][C], int x)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(mat[i][j] == x)
            {
                cout<<"Found at index ("<< i << "," << j << ")";
                return;
            }
        }
    }
    cout<<"Not Found";
}

int main()
{
    cout<<"Search in Row Wise & Column Wise = \n";
    int x=11;
    int mat[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    
    Row_Column_search(mat, x);
    cout<<endl;
}