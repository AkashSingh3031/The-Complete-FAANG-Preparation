<<<<<<< HEAD
public class SelectionSort {
    // Time complexity O(n^2)
    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; ++i) {
            int min = i;
            for (int j = i + 1; j < arr.length; ++j) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int supp = arr[min];
            arr[min] = arr[i];
            arr[i] = supp;
        }
    }

    public static void display(int[] arr) {
        for (int e : arr) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        int[] arr = {7, 34, -12, 11, 20};
        selectionSort(arr);
        display(arr);
    }
}
=======
public class SelectionSort {
    // Time complexity O(n^2)
    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; ++i) {
            int min = i;
            for (int j = i + 1; j < arr.length; ++j) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int supp = arr[min];
            arr[min] = arr[i];
            arr[i] = supp;
        }
    }

    public static void display(int[] arr) {
        for (int e : arr) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        int[] arr = {7, 34, -12, 11, 20};
        selectionSort(arr);
        display(arr);
    }
}
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
