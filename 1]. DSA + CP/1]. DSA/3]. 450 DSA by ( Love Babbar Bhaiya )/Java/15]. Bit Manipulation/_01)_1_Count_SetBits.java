import java.util.*;
import java.io.*;
public class CountSetBitsInInteger {

	static int countSetBits(int n) { 
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
		
		System.out.println(countSetBits(n));

	}

}
