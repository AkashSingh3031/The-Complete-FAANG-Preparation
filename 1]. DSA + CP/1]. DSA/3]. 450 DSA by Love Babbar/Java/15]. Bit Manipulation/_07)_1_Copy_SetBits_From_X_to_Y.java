import java.util.*;
import java.io.*;
public class CopySetBitsFromXtoY {
	
	// At once
	static void CopySetBits(int x, int y, int left, int right) {
		if(left < 1 || right > 32) {
			return;
		}
		int length = (1<<(right-left+1))-1;
		int mask = (length<<(left-1))&y;
		x=x|mask;
	}

	public static void main(String[] args) {
		int x = 10, y=13, l=2, r=3;
        
		CopySetBits(x,y,l,r);
	}

}