import java.util.Scanner;

class BubbleSort {
    public static void main(String[] args) {
        System.out.print("Enter the Total Numbers of Elements: ");

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        System.out.println("Enter " + n + " Elements: ");

        int list[] = new int[n];

        for (int i = 0; i < n; i++) {
            list[i] = input.nextInt();
        }

        Bubble(list, n);
        System.out.println("<==================================>");
        Display(list, n);
        input.close();
    }

    public static void Bubble(int list[], int n) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (list[j] > list[j + 1]) {
                    int temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }

    public static void Display(int list[], int n) {
        for (int i = 0; i < n; i++) {
            System.out.println(list[i]);
        }
    }
}