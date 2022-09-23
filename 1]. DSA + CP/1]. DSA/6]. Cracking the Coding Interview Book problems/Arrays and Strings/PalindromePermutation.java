public class PalindromePermutation {
    public static void main(String[] args) {
        String s = "abcabcd";
        System.out.println(palindrome(s.toLowerCase()));
    }
    public static boolean palindrome(String str){
        int[] arr = new int[128];
        int count = 0;
        for(int i = 0;i<str.length();i++){
            if(str.charAt(i)!=' '){
                if(arr[str.charAt(i)]!=0){
                    arr[str.charAt(i)] -=1;
                    count-=1;
                }
                else
                {
                    arr[str.charAt(i)] +=1;
                    count+=1;
                }
            }
        }
        return (count==1 || count == 0);
    }
}
