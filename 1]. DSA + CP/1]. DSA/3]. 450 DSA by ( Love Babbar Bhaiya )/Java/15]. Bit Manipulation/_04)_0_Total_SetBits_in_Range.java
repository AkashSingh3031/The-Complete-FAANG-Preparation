import java.util.Arrays;

public class TotalSetBits1toN {
	
	static int[] setBitsinRange(int n) { 
		int ans[] = new int[n+1];
		for(int i=1 ; i<=n ; i++) {
			ans[i] = ans[i&(i-1)] + 1 ; 
		}
		return ans;
	}

	public static void main(String[] args) {
		int n = 5;
        System.out.println(setBitsinRange(n));
       
	}

}
