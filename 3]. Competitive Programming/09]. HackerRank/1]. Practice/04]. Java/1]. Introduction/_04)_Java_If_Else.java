 
import java.util.Scanner;

/**
 * 
 * @author Mayur Ingle(https://github.com/thecoder8890)
 * Solution of https://www.hackerrank.com/challenges/java-if-else
 *
 */
public class JavaIfElse {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String ans = "";
		if (n % 2 == 1) {
			ans = "Weird";
		} else {

			if (n >= 6 && n <= 20) {
				ans = "Weird";
			} else {
				ans = "Not Weird";
			}

		}
		System.out.println(ans);
		sc.close();
	}
}
