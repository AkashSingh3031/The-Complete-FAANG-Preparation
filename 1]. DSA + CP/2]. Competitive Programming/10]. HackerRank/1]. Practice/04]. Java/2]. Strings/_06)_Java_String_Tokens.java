<<<<<<< HEAD
import java.io.*;
import java.util.*;

public class JavaStringTokens {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine().trim();
        if (s.length() > 0) {
            String[] tokens = s.split("[ !,?._'@]+");
            System.out.println(tokens.length);
            for (String token : tokens)
                System.out.println(token);
        } else {
            System.out.println(0);
        }
        scan.close();
    }
}
=======
import java.io.*;
import java.util.*;

public class JavaStringTokens {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine().trim();
        if (s.length() > 0) {
            String[] tokens = s.split("[ !,?._'@]+");
            System.out.println(tokens.length);
            for (String token : tokens)
                System.out.println(token);
        } else {
            System.out.println(0);
        }
        scan.close();
    }
}
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
