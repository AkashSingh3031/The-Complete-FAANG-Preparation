<<<<<<< HEAD
import java.util.Scanner;

public class JavaAnagrams {

    static boolean isAnagram(String a, String b) {
        if (a.length() != b.length())
            return false;
        a = a.toLowerCase();
        b = b.toLowerCase();
        int[] letters = new int[26];
        for (int i = 0; i < a.length(); ++i) {
            letters[a.charAt(i) - 'a']++;
            letters[b.charAt(i) - 'a']--;
        }
        for (int l : letters) {
            if (l != 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
=======
import java.util.Scanner;

public class JavaAnagrams {

    static boolean isAnagram(String a, String b) {
        if (a.length() != b.length())
            return false;
        a = a.toLowerCase();
        b = b.toLowerCase();
        int[] letters = new int[26];
        for (int i = 0; i < a.length(); ++i) {
            letters[a.charAt(i) - 'a']++;
            letters[b.charAt(i) - 'a']--;
        }
        for (int l : letters) {
            if (l != 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
