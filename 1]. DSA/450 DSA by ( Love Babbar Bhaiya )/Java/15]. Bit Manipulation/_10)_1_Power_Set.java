import java.util.*;

public class PowerSet {

	static List< List<Integer> > Subset (int a[]){
		List< List<Integer> > output = new ArrayList<>();
		int n = a.length;
		int size = 1<<n;
		for(int i=0 ; i<size ; i++) {
			List<Integer> curr = new ArrayList<>();
			for(int j=0 ; j<n ; j++) {
				if(((i>>j)&i)==1) {
					curr.add(a[j]);
				}
			}
			output.add(curr);
		}
		return output;
	}

	public static void main(String[] args) {
		int a[] = {1,2,3};

        System.out.println(Subset(a));
	}

}