public class URLify {
    public static void main(String[] args) {
        String s = "Mr John Smith    " ;
        int truelength = 13;
        char[] arr = s.toCharArray();
        //System.out.println("array length: "+arr.length+"    string length: "+s.length());
        String answer = urlify(s,truelength);

        System.out.println("Original string: "+s+"\nModified string: "+answer);
    }
    public static String urlify(String str, int truelength)
    {
        char[] arr = str.toCharArray();
        int spaces = 0;
        for(int i = 0;i<truelength;i++)
        {
            if(arr[i] == ' ')
            {
                spaces+=1;
            }
        }
        int newlength = truelength + spaces*2;
        newlength-=1;

        for(int i = truelength-1; i >= 0 ;i--)
        {
            if(arr[i] == ' '){
                arr[newlength] = '0';
                arr[newlength-1] = '2';
                arr[newlength-2] = '%';
                newlength-=3;
            }
            else
            {
                arr[newlength] = arr[i];
                newlength-=1;
            }
        }
        return new String(arr);
    }
}
