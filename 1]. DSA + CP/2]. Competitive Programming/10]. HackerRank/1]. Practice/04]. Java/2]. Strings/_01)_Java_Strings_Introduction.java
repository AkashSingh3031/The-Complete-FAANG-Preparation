<<<<<<< HEAD
import java.io.*;
import java.util.*;

public class JavaStringsIntroduction {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        System.out.println(A.length() + B.length());
        if (A.compareTo(B) > 0)
            System.out.println("Yes");
        else
            System.out.println("No");
        System.out.println(A.substring(0, 1).toUpperCase() + A.substring(1)
                     + " " + B.substring(0, 1).toUpperCase() + B.substring(1));
        sc.close();
    }
=======
import java.io.*;
import java.util.*;

public class JavaStringsIntroduction {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        System.out.println(A.length() + B.length());
        if (A.compareTo(B) > 0)
            System.out.println("Yes");
        else
            System.out.println("No");
        System.out.println(A.substring(0, 1).toUpperCase() + A.substring(1)
                     + " " + B.substring(0, 1).toUpperCase() + B.substring(1));
        sc.close();
    }
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}