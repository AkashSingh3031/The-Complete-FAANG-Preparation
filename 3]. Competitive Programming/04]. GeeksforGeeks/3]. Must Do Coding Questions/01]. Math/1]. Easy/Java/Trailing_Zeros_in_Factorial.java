import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int N = sc.nextInt();
			
            Solution ob = new Solution();
            int ans  = ob.trailingZeroes(N);
            System.out.println(ans);
        }
    }
}

class Solution
{
    static int trailingZeroes(int N)
    {
        // Write your code here
        if(N<0)
            return -1;
        int count=0;
        for(int i=5; N/i>=1; i*=5)
            count += N/i;
        return count;
    }
}
