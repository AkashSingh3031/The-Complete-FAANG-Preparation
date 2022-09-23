public class StringRotation {
    public static void main(String[] args) {
        String s1 = "waterbottle";
        String s2 = "erbottlewat";
        String str = s1+s1;
        System.out.println(isSubstring(str,s2));

    }
    public static boolean isSubstring(String s1, String s2){
        return s1.contains(s2);
    }
}
