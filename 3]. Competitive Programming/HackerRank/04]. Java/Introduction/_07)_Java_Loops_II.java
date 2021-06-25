/**
 * 
 */
 
import java.util.Scanner;

/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 * https://www.hackerrank.com/challenges/java-loops
 *
 */
public class JavaLoopsII {
	public static void main(String[] argh) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int n = in.nextInt();
			int temp = a;
			for (int j = 0; j < n; j++) {
				temp += (Math.pow(2, j) * b);
				System.out.print(temp + " ");
			}
			System.out.println();
		}
		in.close();
	}
}
