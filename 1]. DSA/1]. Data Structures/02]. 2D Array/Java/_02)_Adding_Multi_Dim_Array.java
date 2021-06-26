import java.util.Scanner;

class Adding_Multi_Dim_Array {
    /* Adding Method Of MultiDimentional Arrays */
    static void Adding(int[][] array, int[][] second_array) {
        System.out.println("\t\t\t<<=======================================================>>");
        System.out.println("\t\t\t\tHere's Your Addition of Mutli_Dimentional Matrix::");
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < second_array.length; j++) {
                System.out.print(array[i][j] + second_array[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        /* FIRST MATRIX */
        System.out.println("\t\t\t\tFIRST MATRIX");

        System.out.print("Enter Number of Rows: ");
        int rows = input.nextInt();

        System.out.print("Enter Number of Columns: ");
        int columns = input.nextInt();

        int total = rows * columns;

        int array[][] = new int[rows][columns];

        System.out.println("Enter " + total + " Elements with Row Wise:::: ");
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length; j++) {
                array[i][j] = input.nextInt();
            }
        }

        /*
         * System.out.println("\t\t\t\t\t====================================");
         * System.out.println("Before Adding The Multi_Dimentional Array: ");
         * 
         * for (int i = 0; i < array.length; i++) { for (int j = 0; j < array.length;
         * j++) { System.out.print(array[i][j] + " "); } System.out.println(); }
         */

        /* SECOND MATRIX====================================================== */
        System.out.println("\t\t\t\tSECOND MATRIX");

        int second_array[][] = new int[rows][columns];

        System.out.println("Enter " + total + " Elements with Row Wise:::: ");
        for (int i = 0; i < second_array.length; i++) {
            for (int j = 0; j < second_array.length; j++) {
                second_array[i][j] = input.nextInt();
            }
        }

        /*
         * System.out.println("\t\t\t\t\t====================================");
         * System.out.println("Before Adding The Multi_Dimentional Array: ");
         * 
         * for (int i = 0; i < second_array.length; i++) { for (int j = 0; j <
         * second_array.length; j++) { System.out.print(second_array[i][j] + " "); }
         * System.out.println(); }
         */

        Adding(array, second_array);
        input.close();
    }
}