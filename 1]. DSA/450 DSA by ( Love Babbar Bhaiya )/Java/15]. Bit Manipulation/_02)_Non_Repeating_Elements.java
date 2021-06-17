import java.util.*;
import java.io.*;
public class NonRepeatingElement {

	static int[] twoNumbers1(int a[]) { //first method
		int xor = 0;
		for(int i : a) {
			xor^=i;
		}
		int mask = xor&~(xor-1); // least significant bit
		int first = 0, second = 0;
		for(int i : a) {
			if((i&mask)!=0) {
				first = first^i;
			}
			else {
				second = second^i;
			}
		}
		return new int[] {first,second};
	}
	
	static int[] twoNumbers2(int a[]) {//2nd Method
		int xor = 0;
		for(int i : a) {
			xor^=i;
		}
		int mask = xor&(-xor);
		int first = 0;
		for(int i : a) {
			if((i&mask)!=0) {
				first^=i;
			}
		}
		return new int[] {first,(xor^first)};
	}

	public static void main(String[] args) {
        int n = 2;
		int arr[] = {1, 2, 3, 2, 1, 4};
        twoNumbers1(arr);
        twoNumbers2(arr);
	}

}
