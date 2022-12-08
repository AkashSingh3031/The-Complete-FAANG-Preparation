bool isValid(int matrix[9][9],int x,int y,int val){
    for(int j=0;j<9;j++){
        if(matrix[x][j]==val){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(matrix[i][y]==val){
            return false;
        }
    }
    int subx=x/3 *3;
    int suby=y/3 * 3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[subx + i][suby + j]==val){
                return false;
            }
        }
    }
    return true;
}

bool solve(int matrix[9][9],int i,int j){
    if(i==9){
        return true;
    }
    int ni=0;
    int nj=0;
    if(j==8){
        ni=i+1;
        nj=0;
    }else{
        ni=i;
        nj=j+1;
    }
    if(matrix[i][j]!=0){
        return solve(matrix,ni,nj);
    }
    for(int po=1;po<=9;po++){
        if(isValid(matrix,i,j,po)){
            matrix[i][j]=po;
            if(solve(matrix,ni,nj)){
                return true; // so return
            }else{
                matrix[i][j]=0; //else backtrack and try different combinations.
            }
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix,0,0);
}
