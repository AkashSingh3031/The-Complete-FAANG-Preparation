#include<iostream>
using namespace std;

const int R=4, C=4;
void BTraversal(int mat[R][C])
{
    if(R == 1)
    {
        for(int i=0; i<C; i++)
            cout<<mat[0][i]<<" ";
            cout<<endl;
    }
    else if(C == 1)
    {
        for(int i=0; i<R; i++)
            cout<<mat[i][0]<<" ";
            cout<<endl;
    }
    else
    {
        for(int i=0; i<C; i++)
            cout<<mat[0][i]<<" ";
            cout<<endl;
        for(int i=1; i<R; i++)
            cout<<mat[i][C-1]<<" ";
            cout<<endl;
        for(int i = C-2; i>=0; i--)
            cout<<mat[R-1][i]<<" ";
            cout<<endl;
        for(int i=R-2; i>=1; i--)
            cout<<mat[i][0]<<" ";
            cout<<endl;
    }
}

int main()
{
    cout<<"Boundary Traversal = \n";
    int mat[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    BTraversal(mat);
    cout<<endl;
}
