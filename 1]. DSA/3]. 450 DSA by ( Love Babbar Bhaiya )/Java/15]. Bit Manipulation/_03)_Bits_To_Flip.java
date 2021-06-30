import java.util.*;
import java.io.*;
public class BitsToFlip {
	
	static int bitsToFlip(int a, int b) {
		int xor = a^b;
		// After xor of two numbers, implement number of set bits in xor.
		int count = 0; //setbits
		while(xor != 0) {
			count++; 
			xor&=(xor-1);
		}
		return count; // setbits 
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        int A = 10;
        int B = 20;
        int ans = bitsToFlip(A,B);
        System.out.println(ans);
	}

}