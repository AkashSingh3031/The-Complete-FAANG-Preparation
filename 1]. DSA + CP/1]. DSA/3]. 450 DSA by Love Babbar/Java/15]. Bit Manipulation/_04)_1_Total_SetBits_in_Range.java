import java.util.Arrays;

public class TotalSetBits1toN {
	
	static int SetBitsinRange(int n) {
		int ans[] = new int[n+1];
		for(int i=0 ; i<n ; i++) {
			ans[i] = ans[i&(i-1)] + 1;
		}
		int total = Arrays.stream(ans).sum();
		return total;
	}

	public static void main(String[] args) {
		int n = 5;
        System.out.println(SetBitsinRange(n));
	}

}
