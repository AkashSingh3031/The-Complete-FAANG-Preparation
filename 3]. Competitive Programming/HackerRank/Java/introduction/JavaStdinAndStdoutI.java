import java.util.Scanner;

/**
 * 
 * @author Mayur Ingle(https://github.com/thecoder8890)
 * Solution of https://www.hackerrank.com/challenges/java-stdin-and-stdout-1
 *
 */
public class JavaStdinAndStdoutI {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		sc.close();
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);

	}
}
