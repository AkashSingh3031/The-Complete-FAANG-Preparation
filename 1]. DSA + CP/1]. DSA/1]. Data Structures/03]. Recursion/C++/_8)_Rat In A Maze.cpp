#include<bits/stdc++.h>
using namespace std;
bool find_paths(char maze[10][10],int sol[][10],int row,int col, int n,int m){
    //Base Case
    if(row==n-1&&col==m-1){
        sol[n-1][m-1]=1;
        //Print the path
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                cout<<sol[row][col];
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //Edge cases
    if(row>=n||col>=m){
        return false;
    }
    if(maze[row][col]=='X')
        return false;
    //Assume that solution exists
    sol[row][col]=1;
    bool rightsuccess=find_paths(maze,sol,row,col+1,n,m);
    bool downsucess=find_paths(maze,sol,row+1,col,n,m);
    //Steps after function call are the going back steps
    //Backtrack
    sol[row][col]=0;

    if(rightsuccess||downsucess)
        return true;
    return false;
}
int main(){
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int sol[10][10]={0};
    int n=4;
    int m=4;
    bool ans=find_paths(maze,sol,0,0,n,m);
    if(ans==false)
        cout<<"Path doesnt exist";
}
