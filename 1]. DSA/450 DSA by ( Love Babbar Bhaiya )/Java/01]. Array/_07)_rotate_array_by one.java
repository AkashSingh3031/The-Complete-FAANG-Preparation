/* Write a program to cyclically rotate an array by one.*/
import java.io.*;
import java.util.*;
import java.util.Arrays;

class RotateArray {
    public static void main (String[] args){
		int arr[] = new int[]{1,2,3,4,5};

		int x = arr[arr.length-1],i;
		for( i=arr.length-1;i>0;i--){
			arr[i] = arr[i-1];
		}
		arr[0] = x;

		System.out.println("Rotates array is "+ Arrays.toString(arr));
    }
}
