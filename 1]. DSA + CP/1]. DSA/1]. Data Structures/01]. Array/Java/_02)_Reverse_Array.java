import java.util.Scanner;

class Reverse_Array {
    static int MAX = 10;

    /*
     * Reverse Method with parameter of array, start(Index with 0) , end(Index of
     * last element) and the n for number of elements to be Inserted for Reverse.
     */
    static void Reverse(int array[], int start, int end, int n) {
        int temp;
        while (start < end) {
            /* Changing the array's data with index.. */
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
        System.out.println("\t\t\t\tReversed Array: ");
        for (int i = 0; i < n; i++) {
            System.out.println("\t\t" + array[i] + " ");
        }
        System.out.println();
    }

    /* Main Method */
    public static void main(String[] args) {
        int array[] = new int[MAX];
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Total Number of Elements to be Entered: ");
        int n = input.nextInt();
        System.out.println("Enter Elements which is to be Reversed:  ");
        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }
        int start = 0;
        int size = n - 1;
        Reverse(array, start, size, n);
        input.close();
    }
}
