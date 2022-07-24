<<<<<<< HEAD
import java.util.Scanner;

public class JavaSubstringComparisons {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = s.substring(0, k);
        String largest = s.substring(0, k);
        for (int i = k + 1; i <= s.length(); ++i) {
            String aux = s.substring(i-k, i);
            if (aux.compareTo(smallest) < 0)
                smallest = aux;
            if (aux.compareTo(largest) > 0)
                largest = aux;
        }
        return smallest + "\n" + largest;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
=======
import java.util.Scanner;

public class JavaSubstringComparisons {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = s.substring(0, k);
        String largest = s.substring(0, k);
        for (int i = k + 1; i <= s.length(); ++i) {
            String aux = s.substring(i-k, i);
            if (aux.compareTo(smallest) < 0)
                smallest = aux;
            if (aux.compareTo(largest) > 0)
                largest = aux;
        }
        return smallest + "\n" + largest;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}