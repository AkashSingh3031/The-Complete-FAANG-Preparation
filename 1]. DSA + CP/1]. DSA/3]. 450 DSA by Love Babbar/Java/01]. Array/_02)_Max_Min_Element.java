/* Find the maximum and minimum element in array*/

public class min_max_element {
	public static void main(String[] args) {
		int[] arr = { 1, -3, 6, -2, 23, 5, 3, 7, 9, 87, 56, 45, 12, 34, 20, 23 };
		Pair ans = maxminpair(arr, arr.length - 1);
		System.out.println("Maximum value : "+ans.max);
		System.out.println("Minimum value : "+ans.min);
	}
	public static void maxminarray(int[] arr) {
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] > max) {
				max = arr[i];
				count2++;
			} else {
				count2++;
			}
			if (arr[i] < min) {
				min = arr[i];
				count2++;
			} else {
				count2++;
			}
		}
		System.out.println(max);
		System.out.println(min);
	}
	static class Pair {
		int min;
		int max;
	}
	public static int count = 0;
	public static int count2 = 0;

	public static Pair maxminarrayrecursive(int[] arr, int start, int end) {
		Pair minmax = new Pair();
		Pair mml = new Pair();
		Pair mmh = new Pair();

		int mid = (start + end) / 2;

		if (start == end) {
			minmax.max = arr[start];
			minmax.min = arr[start];
			return minmax;
		}

		mml = maxminarrayrecursive(arr, start, mid);
		mmh = maxminarrayrecursive(arr, mid + 1, end);

		if (mml.min < mmh.min) {
			minmax.min = mml.min;
			count = count + 1;
		} else {
			minmax.min = mmh.min;
			count = count + 1;
		}

		if (mml.max < mmh.max) {
			minmax.max = mmh.max;
			count = count + 1;
		} else {
			minmax.max = mml.max;
			count = count + 1;
		}

		return minmax;
	}

	public static Pair maxminpair(int[] arr, int n) {
		Pair maxmin = new Pair();
		int i = 0, j = 0;
		if (n % 2 == 0) {
			i = 0;
			j = 1;
		} else {
			i = j = 0;
		}
		while (j < arr.length) {
			if (arr[i] < arr[j]) {
				if (maxmin.min > arr[i])
					maxmin.min = arr[i];
				if (maxmin.max < arr[j])
					maxmin.max = arr[j];
			} else {
				if (maxmin.min > arr[j])
					maxmin.min = arr[j];
				if (maxmin.max < arr[i])
					maxmin.max = arr[i];
			}
			i++;
			j++;
		}
		return maxmin;
	}
}
