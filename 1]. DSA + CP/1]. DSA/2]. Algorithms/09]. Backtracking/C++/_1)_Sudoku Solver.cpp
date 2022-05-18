#include<iostream>
#include<math.h>
using namespace std;
bool canPlace(int n,int grid[9][9],int i,int j,int number){
    //row and column check
    for(int row=0;row<n;row++){
        if(grid[i][row]==number or grid[row][j]==number)
            return false;
    }
    //grid
    int rootn=sqrt(n);
    int sx=(i/rootn)*rootn;
    int sy=(j/rootn)*rootn;
    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(grid[x][y]==number)
                return false;
        }
    }
    return true;
}
bool sudoku_solver(int n,int grid[9][9],int i,int j){
    if(i==n){
        //print grid
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n){
        return sudoku_solver(n,grid,i+1,0);
    }
    if(grid[i][j]!=0){
        return sudoku_solver(n,grid,i,j+1);
    }
    //recursive case
    for(int number=1;number<=n;number++){
        if(canPlace(n,grid,i,j,number)){
            grid[i][j]=number;
            bool couldSolve=sudoku_solver(n,grid,i,j+1);
            if(couldSolve)
                return true;
        }
    }
    //back track
    grid[i][j]=0;
    return false;
}
int main(){
    int grid[9][9]=
        {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
    bool ans=sudoku_solver(9,grid,0,0);
    if(!ans){
        cout<<"Could't solve";
    }
}
