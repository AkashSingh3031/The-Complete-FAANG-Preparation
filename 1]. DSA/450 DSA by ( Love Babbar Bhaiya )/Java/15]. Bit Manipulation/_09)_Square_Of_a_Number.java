public class SqaureOfNumber {
	
	static int sqaure(int n) {
		if(n == 0) return 0;
		if(n < 0) n = -n;
		int x = n >> 1;
		if(n % 2 != 0) {
			return ( (sqaure(x) << 2) + (x << 2) + 1);
		}
		else {
			return (sqaure(x) << 2);
		}
	}

	public static void main(String[] args) {
		int n = 2;
        System.out.println(sqaure(n));
	}

}