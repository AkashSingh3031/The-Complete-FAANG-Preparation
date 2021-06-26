import java.util.Scanner;

class BasicArray {
    /* A Method For Creating Array List */
    /* SINGAL DIMENTIONAL ARRAY */
    public static void Create_array(int arr[]) {
        /* Declaration */
        int array[] = new int[5];

        /* Initilization */
        array[0] = 10;
        array[1] = 13;
        array[2] = 34;
        array[3] = 45;
        array[4] = 65;

        /* Print array with Index */
        System.out.println("Print Arrays With Index");
        System.out.println(array[0]);

        System.out.println("Print All Arrays With Loop");

        /* Print all array with iteration */
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }

        /* Getting Input From User to store Data Into Array */
        Scanner input = new Scanner(System.in);

        System.out.print("How many Elements you wanna Add ?: ");
        int n = input.nextInt();

        int array_input[] = new int[n];
        System.out.println("Enter " + n + " Elements: ");
        for (int i = 0; i < n; i++) {
            array_input[i] = input.nextInt();
        }

        System.out.println("Showing The Array with Loop");
        for (int i = 0; i < n; i++) {
            System.out.println("\t" + array_input[i]);
        }
        input.close();

        /* receives an array as a parameter */
        System.out.println("Receiving  array as a parameter");
        for (int i = 0; i < arr.length; i++)
            System.out.println(arr[i]);

        System.out.println();
    }

    /* Main Method */
    public static void main(String[] args) {
        Create_array(new int[] { 10, 22, 44, 66 });
    }
}
