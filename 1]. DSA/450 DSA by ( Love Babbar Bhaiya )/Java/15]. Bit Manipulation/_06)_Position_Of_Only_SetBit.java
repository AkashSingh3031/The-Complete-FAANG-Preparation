public class PositionOfOnlySetBit {
	
	static boolean isPowerOf2(int n) {
		return (n>0 && (n&(n-1))==0) ? true : false ;
	}
	
	static int position(int N) {
		if(!isPowerOf2(N)) return -1;
		int num = 1, position = 1;
		while((num & N)==0) {
			num<<=1;
			position++;
		}
		return position;
	}

	public static void main(String[] args) {
		int n = 4;
        int ans = position(4);
        System.out.println(ans);
	}

}