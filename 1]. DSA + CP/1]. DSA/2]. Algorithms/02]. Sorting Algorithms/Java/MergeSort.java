import java.util.Scanner;

public class MergeSort {
    static int MAX = 10;

    public static void main(String[] args) {
        int A[] = new int[MAX];
        int high, low;
        Scanner input = new Scanner(System.in);
        System.out.println("\t\t\tSorting Using Merge Sort");
        System.out.println("How Many Elements Wanna Add? : ");
        int n = input.nextInt();
        System.out.println("Enter " + n + " Elements: ");
        for (int i = 0; i < n; i++) {
            A[i] = input.nextInt();
        }
        low = 0;
        high = n - 1;
        Merge(A, low, high);
        Display(A, n);
        input.close();
    }
    /* ALgorithm of MergeSort */

    public static void Merge(int A[], int low, int high) {
        int mid;
        // void Combine
        if (low < high) {
            mid = (low + high) / 2;
            Merge(A, low, mid);
            Merge(A, mid + 1, high);
            Combine(A, low, mid, high);
        }
    }

    /* Combining Method */
    public static void Combine(int A[], int low, int mid, int high) {
        int i, j, k;
        int[] temp = new int[MAX];
        k = low;
        i = low;
        j = mid + 1;
        while (i <= mid && j <= high) {
            if (A[i] <= A[j]) {
                temp[k] = A[i];
                i++;
                k++;
            } else {
                temp[k] = A[j];
                j++;
                k++;
            }
        }
        while (i <= mid) {
            temp[k] = A[i];
            i++;
            k++;
        }
        while (j <= high) {
            temp[k] = A[j];
            j++;
            k++;
        }
        for (k = low; k <= high; k++) {
            A[k] = temp[k];
        }
    }

    /* Displaying Output */

    static void Display(int A[], int n) {
        System.out.println("\t\t The Sorted List:...");
        for (int i = 0; i < n; i++) {
            System.out.println(A[i] + "\t");
        }
    }
}