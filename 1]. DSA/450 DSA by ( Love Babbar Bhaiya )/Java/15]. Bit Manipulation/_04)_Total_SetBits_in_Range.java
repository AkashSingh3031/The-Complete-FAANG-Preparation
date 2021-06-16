import java.util.Arrays;

public class TotalSetBits1toN {
	
	static int[] setBitsinRange(int n) { 
		int ans[] = new int[n+1];
		for(int i=1 ; i<=n ; i++) {
			ans[i] = ans[i&(i-1)] + 1 ; 
		}
		return ans;
	}
	
	static int SetBitsinRange(int n) {
		int ans[] = new int[n+1];
		for(int i=0 ; i<n ; i++) {
			ans[i] = ans[i&(i-1)] + 1;
		}
		int total = Arrays.stream(ans).sum();
		return total;
	}
	
	// log(N) complexity
	static int totalSetBits(int n) {
		int N = n+1;
		int powerOf2 = 2;
		int count = N / 2;
		while(powerOf2 <= N) {
			int total_pairs = N / powerOf2;
			count += (total_pairs / 2) * powerOf2;
			count += (total_pairs % 2 == 1) ? (N % powerOf2) : 0 ;
			powerOf2<<=1;
		}
		return count;
	}

	public static void main(String[] args) {
		int n = 5;
        System.out.println(setBitsinRange(n));
        System.out.println(SetBitsinRange(n));
        System.out.println(totalSetBits(n));
	}

}
