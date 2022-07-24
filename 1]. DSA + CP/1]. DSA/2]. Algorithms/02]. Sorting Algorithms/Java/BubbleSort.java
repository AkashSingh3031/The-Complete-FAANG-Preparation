public class BubbleSort {

    // Time complexity O(n^2)
    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; ++i) {
            for (int j = 0; j < arr.length - i - 1; ++j) {
                if (arr[j] > arr[j+1]) {
                    int supp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = supp;
                }
            }
        }
    }

    public static void display(int[] arr) {
        for (int e : arr) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        int[] arr = {7, 34, -12, 11, 20};
        bubbleSort(arr);
        display(arr);
    }
}
