/*Find the Union and Intersection of the two sorted arrays.*/

import java.util.HashSet;

class Union_intersection{
	public static void main(String[] args) {

		int[] arr1 = { 1, 2, 3, 4, 5, 6 };
		int[] arr2 = { 5, 6, 7, 8, 9 };

		unionhashmap(arr1, arr2);
		printIntersection(arr1, arr2);

	}

	public static void unionhashmap(int[] arr1, int[] arr2) {

		HashSet<Integer> union = new HashSet<Integer>();
		for (int i = 0; i < arr1.length; i++) {
			union.add(arr1[i]);
		}
		for (int i = 0; i < arr2.length; i++) {
			union.add(arr2[i]);
		}
		System.out.println(union);
	}

	static void printIntersection(int arr1[], int arr2[]) {
		HashSet<Integer> hs = new HashSet<>();
		HashSet<Integer> hs1 = new HashSet<>();

		for (int i = 0; i < arr1.length; i++)
			hs.add(arr1[i]);

		for (int i = 0; i < arr2.length; i++)
			if (hs.contains(arr2[i]))
				System.out.print(arr2[i] + " ");
	}

	public static int[] unionIntersection(int[] arr1, int[] arr2) {
		int[] temp = new int[arr1.length + arr2.length];

		for (int i = 0; i < arr1.length; i++) {
			temp[i] = arr1[i];
		}
		for (int i = 0; i < arr2.length; i++) {
			int flag = 0;
			for (int j = 0; j < arr1.length; j++) {
				if (arr2[i] == arr1[j]) {
					flag = 1;
				}
			}
			if (flag == 0) {
				temp[arr1.length + i] = arr2[i];
			}
		}

		return temp;
	}

	public static boolean search(int[] arr, int no) {
		int lo = 0, hi = arr.length - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] > no) {
				hi = mid - 1;
			} else if (arr[mid] < no) {
				lo = mid + 1;
			} else {
				return true;
			}
		}

		return false;

	}

}
