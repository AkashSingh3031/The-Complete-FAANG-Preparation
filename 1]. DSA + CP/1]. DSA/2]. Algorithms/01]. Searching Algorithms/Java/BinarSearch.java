import java.util.Scanner;

public class BinarSearch {
    // The Max variable is to store maximum value of array..
    static int MAX = 10;

    // The variable arr[] is the collection of same element where our elements are
    // to be added.

    // The variable first is the index of the array which starts with 0.

    // The variable last is the index of the last element which is n-1.

    // The variable key is thesearch elementwhich isto be searched...

    // The variable mid will come from the first index + last index of array which
    // is divided by 2.

    public static void binarySearch(int arr[], int first, int last, int key) {
        int mid = (first + last) / 2;
        while (first <= last) {
            if (arr[mid] < key) {
                first = mid + 1;
            } else if (arr[mid] == key) {
                System.out.println("Element is found at index: " + mid);
                break;
            } else {
                last = mid - 1;
            }
            mid = (first + last) / 2;
        }
        if (first > last) {
            System.out.println("Element is not found!");
        }
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        System.out.print("How Many Elements To Be Add ?:");
        int n = input.nextInt();
        System.out.println("Enter The Elements.: ");
        int arr[] = new int[MAX];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        System.out.println("Enter The Elements  Which Is To Be Searched..: ");
        int key = input.nextInt();
        int last = arr.length - 1;
        binarySearch(arr, 0, last, key);
        input.close();
    }
}