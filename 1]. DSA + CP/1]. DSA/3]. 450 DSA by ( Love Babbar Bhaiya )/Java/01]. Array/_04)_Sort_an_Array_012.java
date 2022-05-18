/* Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo*/
import java.io.*;
import java.util.*;

class Solution{
    public static void sort012(int a[], int n){
        int zeroCount = 0;
         int oneCount = 0;
         for (int i = 0; i < a.length; i++){
              if (a[i] == 0)
                  zeroCount++;
              if (a[i] == 1)
                   oneCount++;
        }
        for (int i = 0; i < zeroCount; i++){
            a[i] = 0;
        }
       for (int i = zeroCount; i < (zeroCount + oneCount); i++){
            a[i] = 1;
       }
      for (int i = (zeroCount + oneCount); i < a.length; i++) {
            a[i] = 2;
      }
    }
}

class zeros_ones_twos {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            int arr[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            Solution ob=new Solution();
            ob.sort012(arr, n);
            StringBuffer str = new StringBuffer();
            for(int i=0; i<n; i++){
                str.append(arr[i]+" ");
            }
            System.out.println(str);
        }
    }
}
