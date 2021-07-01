import java.util.Scanner;

class SelectionSort {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter Total Number of Elements of List: ");
        int n = input.nextInt();

        int list[] = new int[n];

        System.out.println("Enter The Elements of List: ");

        for (int i = 0; i < list.length; i++) {
            list[i] = input.nextInt();
        }

        int first = list.length;

        int last = n - 1;

        System.out.println("\t\t<===============================================================>");

        print(list, n);

        Selection(list, n, first, last);

        System.out.println("\t\t\t\t\t Sorted List using Selection Sort Technique========");

        print(list, n);

        input.close();
    }

    public static void Selection(int list[], int n, int first, int last) {

        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array

            int minimum = i;

            for (int j = i + 1; j < n; j++) {

                if (list[j] < list[minimum]) {
                    minimum = j;
                }
            }
            // Swap the found minimum element with the first element

            int temp = list[minimum];

            list[minimum] = list[i];

            list[i] = temp;
        }
    }

    /* Printing List */
    public static void print(int list[], int n) {

        for (int i = 0; i < list.length; i++) {

            System.out.println(list[i]);
        }
    }
}
