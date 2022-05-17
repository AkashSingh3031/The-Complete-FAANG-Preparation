import java.util.Scanner;

public class InsertionSort {

    public static void Insertion(int A[], int n) {
        int temp;
        for (int i = 1; i <= n-1; i++) {
            temp = A[i];
            int j = i - 1;
            while ((j >= 0) && (A[j] > temp)) {
                A[j + 1] = A[j];
                j = j - 1;
            }
            A[j + 1] = temp;
        }
        System.out.println("The Sorted List of Elements : ");
        for (int i = 0; i < n; i++) {
            System.out.println("\n" + A[i]);
        }
    }

    public static void main(String[] args) {
        int A[] = new int[10];
        System.out.println("\t\tINSERTION SORT:");
        Scanner input = new Scanner(System.in);
        System.out.print("How Many Elements Are There? : ");
        int n = input.nextInt();
        System.out.println("Enter Elements: ");
        for (int i = 0; i < n; i++) {
            A[i] = input.nextInt();
        }
        Insertion(A, n);
        input.close();
    }
}
