/*Minimum no. of Jumps to reach end of an array*/
import java.io.*;
import java.util.*;
import java.util.Arrays;

class min_jumps{
	static int minJumps(int arr[],int n)
	    {
	        int[] jumps = new int[n];
	        int min;
	        jumps[n - 1] = 0;

	        for (int i = n - 2; i >= 0; i--) {

	            if (arr[i] == 0)
	                jumps[i] = Integer.MAX_VALUE;

	            else if (arr[i] >= n - i - 1)
	                jumps[i] = 1;

	            else {
	                min = Integer.MAX_VALUE;

	                for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
	                    if (min > jumps[j])
	                        min = jumps[j];
	                }

	                if (min != Integer.MAX_VALUE)
	                    jumps[i] = min + 1;
	                else
	                    jumps[i] = min;
	            }
	        }

	        return jumps[0];
	    }


	    public static void main(String[] args)
	    {
	        int[] arr = {1,3,5,8,9,2,6,7,6,8,9};
	        int size = arr.length;
	        System.out.println("Minimum number of jumps to reach end is " + minJumps(arr, size));
    }
}
