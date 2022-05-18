/* find Largest sum contiguous Subarray [V. IMP].
Kadane's Algorithm*/
import java.io.*;
import java.util.*;
import java.util.Arrays;

class Contagious_subarray{
	public static void main (String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int n = in.nextInt();
		int sum=0;
		int [] arr = new int[t];
		for(int i=0; i<t; i++){
			arr[i] = in.nextInt();
		}
		for(int j=0; j<t; j++){
			sum = sum + maxSubArraySum(arr);
		}
		System.out.println(sum);
    }

    static int maxSubArraySum(int a[]){
        int size = a.length;
        int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;
		while(size!=0){
			for (int i = 0; i < size; i++){
				max_ending_here = max_ending_here + a[i];
				if (max_so_far < max_ending_here)
					max_so_far = max_ending_here;
				if (max_ending_here < 0)
					max_ending_here = 0;
			}
			size--;
		}
        return max_so_far;
    }
}
