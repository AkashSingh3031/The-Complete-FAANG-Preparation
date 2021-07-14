/*
Tic-tac-toe is a game played between two players on a 3×3 grid. In a turn, a player chooses an empty cell and places their symbol on the cell. 
The players take alternating turns, where the player with the first turn uses the symbol X and the other player uses the symbol O. 
The game continues until there is a row, column, or diagonal containing three of the same symbol (X or O), and the player with that token is declared the winner. 
Otherwise if every cell of the grid contains a symbol and nobody won, then the game ends and it is considered a draw.
You are given a tic-tac-toe board A after a certain number of moves, consisting of symbols O, X, and underscore(_). Underscore signifies an empty cell.
Print
1: if the position is reachable, and the game has drawn or one of the players won.
2: if the position is reachable, and the game will continue for at least one more move.
3: if the position is not reachable.
Note:
Starting from an empty board, reachable position means that the grid is possible after a finite number of moves in the game where the players may or 
may not be playing optimally. The answer for each testcase should be with respect to the present position and independent of the results in the further successive moves.
Sample Input
3
XOX
XXO
O_O
XXX
OOO
___
XOX
OX_
XO_
Sample Output
2
3
1
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ll t; cin>>t;
    while(t--){
        int cx=0,co=0,c_=0;
        char a[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
                if(a[i][j]=='X') cx++;
                if(a[i][j]=='O') co++;
                if(a[i][j]=='_') c_++;
            }
        }
        int wx=0,wo=0;


        if(a[0][0]=='X' && a[1][0]=='X' && a[2][0]=='X') wx=1;
        if(a[0][1]=='X' && a[1][1]=='X' && a[2][1]=='X') wx=1;
        if(a[0][2]=='X' && a[1][2]=='X' && a[2][2]=='X') wx=1;
        if(a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X') wx=1;
        if(a[0][0]=='X' && a[0][1]=='X' && a[0][2]=='X') wx=1;
        if(a[1][0]=='X' && a[1][1]=='X' && a[1][2]=='X') wx=1;
        if(a[2][0]=='X' && a[2][1]=='X' && a[2][2]=='X') wx=1;
        if(a[0][2]=='X' && a[1][1]=='X' && a[2][0]=='X') wx=1;

        if(a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O') wo=1;
        if(a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O') wo=1;
        if(a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O') wo=1;
        if(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O') wo=1;
        if(a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O') wo=1;
        if(a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O') wo=1;
        if(a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O') wo=1;
        if(a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O') wo=1;

      if((wx==1 && wo==1)||((cx-co)<0)||(cx-co)>1) cout << 3 << endl;
      else if(cx==0 && co==0 && c_==9) cout<<2<<endl;
      else if(wx==1 && wo==0 && cx >co) cout<<1<<endl;
      else if(wx==0 && wo==1 && cx== co) cout<<1<<endl;
      else if(wx==0 && wo==0 && c_==0) cout<<1<<endl;
      else if(wx==0 && wo==0 && c_>0) cout<<2<<endl;
      else cout<<3<<endl;
    }
    return 0;
}
