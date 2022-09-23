import java.util.HashSet;
import java.util.Set;

public class IsUnique {
    public static void main(String[] args) {
        String s = "abcdefzvmkl";

        char[] arr = new char[128];
        if(s.length()>128)
        {
            System.out.println("Not unique");
            return;
        }
        for(int i = 0;i<s.length();i++)
        {
            if(arr[s.charAt(i)] == s.charAt(i))
            {
                System.out.println("Not unique");
                return;
            }
            arr[s.charAt(i)] = s.charAt(i);
        }
        System.out.println("Unique");


    //Using sets
    /*    if(isunique(s))
        {
            System.out.println("Unique");
        }
        else
        {
            System.out.println("Not unique");
        }
    */
    }

    public static boolean isunique(String s)//using set
    {
        Set<Character> set = new HashSet<Character>();
        int i = 0;
        while(i<s.length())
        {
            if(set.contains(s.charAt(i)))
            {
                return false;
            }
            else
            {
                set.add(s.charAt(i++));
            }
        }
        return true;
    }
}
