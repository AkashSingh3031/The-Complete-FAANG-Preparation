/*Move all the negative elements to one side of the array*/

import java.io.*;
import java.util.*;

class move_negandpos {
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
	    int arr[] = {1,9,-3,-5,-11,4,7};
	    int temp;
	    for(int i=0; i<arr.length;i++){
	        for(int j=i+1; j<arr.length;j++){
    	        if(arr[i]>arr[j]){
    	            temp = arr[i];
    	            arr[i] = arr[j];
    	            arr[j] = temp;
    	        }
	        }
	    }
	    for(int j=0; j<arr.length;j++){
    	   System.out.print(arr[j]+" ");
	   }
	   System.out.println();

	}
}
