<<<<<<< HEAD
import java.io.*;
import java.util.*;

public class JavaStringReverse {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B = "";
        for (int i = 0; i < A.length(); ++i) {
            B = A.charAt(i) + B;
        }
        if (A.equals(B))
            System.out.println("Yes");
        else
            System.out.println("No");
        sc.close();   
    }
=======
import java.io.*;
import java.util.*;

public class JavaStringReverse {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B = "";
        for (int i = 0; i < A.length(); ++i) {
            B = A.charAt(i) + B;
        }
        if (A.equals(B))
            System.out.println("Yes");
        else
            System.out.println("No");
        sc.close();   
    }
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}