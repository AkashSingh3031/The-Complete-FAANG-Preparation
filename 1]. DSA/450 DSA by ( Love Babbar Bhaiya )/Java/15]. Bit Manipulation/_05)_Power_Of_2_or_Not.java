public class PowerOf2orNot {
	
	static boolean isPowerOf2(int n) {
		if(n <= 0) return false;
		// Implement number of set bits
		int setBits = 0;
		while(n != 0) {
			setBits++;
			n&=(n-1);
		}
		if(setBits == 1) return true;
		return false;
	}

	public static void main(String[] args) {
		int n = 4;
        System.out.println(isPowerOf2(n));
	}

}
