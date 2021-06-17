import java.util.*;
import java.io.*;
public class Division {
	
	static int divide(int dividend, int divisor) {
		if(dividend==Integer.MIN_VALUE && divisor==-1) {
			return Integer.MAX_VALUE;
		}
		int result = 0;
		int a = Math.abs(dividend);
		int b = Math.abs(divisor);
		for(int i=31 ; i>=0 ; i--) {
			if((a >>> i) - b >= 0) {
				result += 1<<i;
				a -= b<<i;
			}
		}
		return (dividend > 0) == (divisor > 0) ? result : -result;
	}

	public static void main(String[] args) {
		int a = 4, b = 2;
		System.out.println(divide(a,b));
	}

}
