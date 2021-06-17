import java.util.*;
import java.io.*;
public class CountSetBitsInInteger {
	
	static int countSetBits(int n) { 
		int setBits = 0;
		while(n!=0) {
			setBits++;
			n&=(n-1);
		}
		return setBits;
	}

	public static void main(String[] args) {

		int n = 10;
		
		System.out.println(countSetBits(n));

	}

}
