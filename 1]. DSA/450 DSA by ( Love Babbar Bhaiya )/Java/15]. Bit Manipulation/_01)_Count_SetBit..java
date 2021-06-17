import java.util.*;
import java.io.*;
public class CountSetBitsInInteger {
	
	static int countSetBits1(int n) { //Method 1
		int setBits = 0;
		while(n!=0) {
			setBits++;
			n&=(n-1);
		}
		return setBits;
	}
	
	static int countSetBits2(int n) { // Method 2
		int setBits = 0, bitMask = 1;
		for(int i=0 ; i<32 ; i++) {
			if((n & bitMask)!=0) {
				setBits++;
			}
			bitMask<<=1;
		}
		return setBits;
	}

	public static void main(String[] args) {

		int n = 10;
		
		System.out.println(countSetBits1(n));
		
		System.out.println(countSetBits2(n));

	}

}
