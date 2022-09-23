import java.util.Locale;

public class IsPermutation {
    public static void main(String[] args) {
        String s1 = "Abcde";
        String s2 = "Edbca";
        if(ispermutation(s1,s2)){
            System.out.println("Permutation");
        }
        else{
            System.out.println("Not permutation");
        }

    }
    public static boolean ispermutation(String s1, String s2){
        if(s1.length() != s2.length())
        {
            return false;
        }
        String s3 = sort(s1.toLowerCase());
        String s4 = sort(s2.toLowerCase());
        System.out.println("s1:"+s3+"   s2:"+s4);
        return s3.equals(s4);
    }
    public static String sort(String s)
    {
        char[] arr1 = s.toCharArray();
        java.util.Arrays.sort(arr1);
        return new String(arr1);
    }
}
