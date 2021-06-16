/**
 * 
 */
 
import java.util.Scanner;

/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 * https://www.hackerrank.com/challenges/java-loops
 *
 */
public class JavaLoopsI {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		for (int i = 1; i <= 10; i++) {
			System.out.println(N + " x " + i + " = " + N * i);
		}
		in.close();
	}
}
