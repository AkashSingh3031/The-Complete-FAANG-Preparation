 
import java.util.Scanner;

/**
 * 
 * @author Mayur Ingle(https://github.com/thecoder8890)
 * Solution of https://www.hackerrank.com/challenges/java-if-else
 */
public class JavaStdinAndStdoutII {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i = sc.nextInt();
		double d = sc.nextDouble();
		sc.nextLine();
		String s = sc.nextLine();
		sc.close();
		System.out.println("String: " + s);
		System.out.println("Double: " + d);
		System.out.println("Int: " + i);
	}
}
