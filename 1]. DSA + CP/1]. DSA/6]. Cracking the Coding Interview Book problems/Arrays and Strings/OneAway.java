public class OneAway {
    public static void main(String[] args) {
        String s1 = "pales";
        String s2 = "pale";
        if(oneEdit(s1,s2)){
            System.out.println("true");
        }
        else
        {
            System.out.println("false");
        }
    }
    public static boolean oneEdit(String s1, String s2){
        if(Math.abs(s1.length()-s2.length())>1){
            return false;
        }
        String smaller = s1.length() < s2.length()? s1 : s2;
        String longer = s1.length() < s2.length() ? s2:s1;
        int index1 = 0;
        int index2 = 0;
        boolean flag = false;
        while(index1 < smaller.length() && index2 < longer.length()){
            if(smaller.charAt(index1) != longer.charAt(index2)){
                if(flag){
                    return false;
                }
                flag = true;
                if(smaller.length() == longer.length())
                {
                    index1++;
                    index2++;
                }
                else{

                    index2++;
                }

            }
            else{
                index1++;
                index2++;
            }

        }
        return true;
    }
}
