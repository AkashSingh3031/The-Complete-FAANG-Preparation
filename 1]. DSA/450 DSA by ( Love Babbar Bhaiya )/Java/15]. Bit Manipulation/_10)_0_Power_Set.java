import java.util.*;

public class PowerSet {
	
	static List< List<Integer> > subset (int a[]){
		List< List<Integer> > output = new ArrayList<>();
		int n = a.length;
		for(int i=(int) Math.pow(2, n) ; i<Math.pow(2, n+1) ; i++) {
			String bitMask = Integer.toBinaryString(i).substring(1);
			List<Integer> curr = new ArrayList<>();
			for(int j=0 ; j<n ; j++) {
				if(bitMask.charAt(j) == '1') {
					curr.add(a[j]);
				}
			}
			output.add(curr);
		}
		return output;
	}

	public static void main(String[] args) {
		int a[] = {1,2,3};
        System.out.println(subset(a));

	}

}