import java.util.Scanner;

class MultiDimArray {

    public static void Create_Multi() {

        // declaring and initializing 2D array
        int arr[][] = { { 1, 2, 3 }, { 2, 4, 5 }, { 4, 4, 5 } };
        // printing 2D array
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("\t\t" + arr[i][j] + " ");
            }
            System.out.println();
        }

        Scanner input = new Scanner(System.in);
        /* Getting Input From User while Creating MultiDimentional Array */
        System.out.print("Enter Number of Elements for Row: ");
        int row = input.nextInt();
        System.out.print("Enter Number of Elements for Column: ");
        int column = input.nextInt();
        int array[][] = new int[row][column];
        System.out.println("Enter Elements: ");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                array[i][j] = input.nextInt();
            }
        }

        /* Showing Array with For loop */
        System.out.println("Showing Arrays: ");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                System.out.print(array[i][j] + "\t");
            }
            System.out.println();
        }
        input.close();
    }

    public static void main(String[] args) {
        Create_Multi();
    }
}
