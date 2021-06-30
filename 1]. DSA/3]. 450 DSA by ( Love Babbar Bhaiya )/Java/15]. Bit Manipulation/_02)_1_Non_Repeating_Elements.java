import java.util.*;
import java.io.*;
public class NonRepeatingElement {
	
	static int[] twoNumbers(int a[]) {
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
        twoNumbers(arr);
	}

}
