import java.io.*;
import java.util.*;

class GFG 
{
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) 
        {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] array = new int[n - 1];
            for (int i = 0; i < n - 1; i++) 
            {
                array[i] = Integer.parseInt(str[i]);
            }
            Solution sln = new Solution();
            System.out.println(sln.MissingNumber(array, n));
        }
    }
}

class Solution {
    int MissingNumber(int array[], int n) 
    {
        // Your Code Here
        int total = n*(n+1)/2;
        int s=0;
        for(int i=0; i<n-1; i++)
            s += array[i];
        return total-s;
    }
}
