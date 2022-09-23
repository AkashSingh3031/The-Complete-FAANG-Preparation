public class StringCompression {
    public static void main(String[] args) {
        String str = "aabcccccaaa";
        System.out.println(compressedString(str));

    }
    public static String compressedString(String s){
        int finalLength = compress(s);

        //System.out.println(finalLength);
        if(finalLength > s.length()){
            return s;
        }
        StringBuilder str = new StringBuilder(finalLength);
        int count = 0;
        for(int i = 0;i<s.length();i++){
            count++;
            if(i+1>=s.length() || s.charAt(i)!=s.charAt(i+1)){
                str.append(s.charAt(i));
                str.append(count);
                count = 0;
            }
        }
        return new String(str);
    }
    public static int compress(String s){
        int compressedLength = 0;
        int count = 0;

        for(int i = 0;i<s.length();i++){
            count++;
            if(i+1>=s.length() || s.charAt(i)!=s.charAt(i+1)){

                compressedLength += 1+ String.valueOf(count).length();
                count = 0;
            }
        }
        return compressedLength;
    }
}
