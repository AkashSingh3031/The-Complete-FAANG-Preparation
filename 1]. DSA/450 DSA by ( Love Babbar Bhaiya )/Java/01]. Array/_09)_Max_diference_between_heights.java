/* Minimise the maximum difference between heights [V.IMP]*/
import java.io.*;
import java.util.*;
import java.util.Arrays;

class maxdiff_between_heights{
	static int getMinDiff(int arr[], int n, int k)
	    {
	        if (n == 1)
	        return 0;

	        // Sort all elements
	        Arrays.sort(arr);

	        // Initialize result
	        int ans = arr[n-1] - arr[0];

	        int small = arr[0] + k;
	        int big = arr[n-1] - k;
	        int temp = 0;

	        if (small > big)
	        {
	            temp = small;
	            small = big;
	            big = temp;
	        }

	        // Traverse middle elements
	        for (int i = 1; i < n-1; i ++)
	        {
	            int subtract = arr[i] - k;
	            int add = arr[i] + k;

	            // If both subtraction and addition
	            // do not change diff
	            if (subtract >= small || add <= big)
	                continue;
            
	            if (big - subtract <= add - small)
	                small = subtract;
	            else
	                big = add;
	        }

	        return Math.min(ans, big - small);
	    }

	    public static void main(String[] args)
	    {
	        int arr[] = {1,10,14,14,15};
	        int n = arr.length;
	        int k = 6;
	        System.out.println("Maximum difference is "+getMinDiff(arr, n, k));
    }
}
