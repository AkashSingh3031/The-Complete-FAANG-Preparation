import java.util.Arrays;
import java.util.Scanner;

class MergeArrayExample1 {
    public static void main(String[] args) {
        System.out.print("Enter number of First Array's Element: ");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int firstArray[] = new int[n];
        System.out.println("Enter " + n + " Elements: ");
        for (int i = 0; i < n; i++) {
            firstArray[i] = input.nextInt();
        }
        System.out.print("Enter Number of Second Array's Element: ");
        int n1 = input.nextInt();
        System.out.println("Enter " + n1 + " Elements: ");
        int secondArray[] = new int[n1];
        for (int i = 0; i < n1; i++) {
            secondArray[i] = input.nextInt();
        }

        int[] result = new int[n + n1];

        /*
         * For Copying array to another array: System.arraycopy(Object src, int srcPos,
         * Object dest, int destPos, int length)
         */
        System.arraycopy(firstArray, 0, result, 0, n);
        System.arraycopy(secondArray, 0, result, n, n1);
        System.out.println(Arrays.toString(result));

        input.close();
    }
}