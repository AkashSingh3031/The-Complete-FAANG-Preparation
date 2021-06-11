/*Find the "Kth" max and min element of an array */
import java.io.*;
import java.util.*;
class kthmaxmin {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);

		int t=sc.nextInt();

		while(t-->0)
		{
		    int n=sc.nextInt();

		    int arr[]=new int[n];

		    for(int i=0;i<n;i++)
		    arr[i]=sc.nextInt();

		    int k=sc.nextInt();
		    Solution ob = new Solution();

		    System.out.println("kth minimum value is : "+ob.kthSmallest(arr, 0, n-1, k));
		    System.out.println("kth maximum value is : "+ob.kthLargest(arr, 0, n-1, k));
		}
	}
}

class Solution{
    public static int kthSmallest(int[] arr, int l, int r, int k)
    {
        
        int t=0, a=0;

    Arrays.sort(arr);


    for(int i=0; i<k;i++){
        if(i==k-1)
            a = arr[k-1];
    }
    return a;
    }
    public static int kthLargest(int[] arr, int l, int r, int k)
	    {
	     
	        int t=0, b=0;

	    Arrays.sort(arr);

	for(int i=0; i<r+1;i++){
       for(int j=i+1; j<r+1;j++){
            if(arr[i]<arr[j]){
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
   for(int i=0; i<k;i++){
	   if(i==k-1)
			   b = arr[k-1];
	   }
	return b;
    }
}
