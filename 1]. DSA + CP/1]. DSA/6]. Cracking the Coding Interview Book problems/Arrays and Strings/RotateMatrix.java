import java.util.Scanner;

public class RotateMatrix {
    public static void main(String[] args) {
        int r = 3;
        int c = 3;
        int count = 1;
        System.out.println("start");
        int[][] mat = new int[r][c];
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
             mat[i][j] = count++;
            }
        }

        rotate(mat);

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }



    }
    public static void rotate(int[][] mat){
        for(int i = 0;i<mat.length;i++){
            for(int j = i;j<mat[0].length;j++){
                swap(mat,i,j);
            }
        }
        for(int[] arr : mat){
            int low = 0;
            int high = mat[0].length-1;
            while(low<high){
                swap(arr,low,high);
                low++;
                high--;
            }
        }
    }
    public static void swap(int[][] mat,int i,int j){
        int temp = mat[i][j];
        mat[i][j] = mat[j][i];
        mat[j][i] = temp;
    }
    public static void swap(int[] mat,int i,int j){
        int temp = mat[j];
        mat[j] = mat[i];
        mat[i] = temp;
    }
}
