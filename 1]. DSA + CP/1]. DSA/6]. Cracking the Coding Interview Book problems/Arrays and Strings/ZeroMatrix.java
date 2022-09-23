import java.util.Scanner;

public class ZeroMatrix {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int r = scan.nextInt();
        int c = scan.nextInt();
        int[][] matrix = new int[r][c];
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                matrix[i][j] = scan.nextInt();
            }
        }
        makeZeroMatrix(matrix);
        for(int i = 0;i<r;i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(matrix[i][j]+" ");;
            }
            System.out.println("");
        }
    }
    public static void makeZeroMatrix(int[][] mat){
        boolean zeroRow = false;
        boolean zeroColumn = false;
        for(int i = 0;i<mat.length;i++){
            if(mat[i][0] == 0){
                zeroRow = true;
            }
        }
        for(int i = 0;i<mat[0].length;i++){
            if(mat[0][i] == 0){
                zeroColumn = true;
            }
        }

        //Making the inner matrix zero
        for(int i = 1;i< mat.length;i++){
            for(int j = 1;j<mat[0].length;j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i = 1;i< mat.length;i++){
            if(mat[i][0] == 0){
                for(int j = 1;j<mat[0].length;j++){
                    mat[i][j] = 0;
                }
            }
        }
        for(int i = 1;i< mat[0].length;i++){
            if(mat[0][i] == 0){
                for(int j = 1;j<mat.length;j++){
                    mat[j][i] = 0;
                }
            }
        }
        if(zeroRow){
            for(int i = 0;i< mat.length;i++){
                mat[i][0] = 0;
            }
        }
        if(zeroColumn){
            for(int i = 0;i<mat[0].length;i++){
                mat[0][i] = 0;
            }
        }
    }

}
