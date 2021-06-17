/**
 * solution : https://www.hackerrank.com/challenges/java-inheritance-2

 */ 
/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 *
 */

// Write your code here
class Arithmetic {
	int add(int a, int b) {
		return a + b;
	}
}

class Adder extends Arithmetic {

}

public class JavaInheritanceII {
	public static void main(String[] args) {
		// Create a new Adder object
		Adder a = new Adder();

		// Print the name of the superclass on a new line
		System.out.println("My superclass is: " + a.getClass().getSuperclass().getName());

		// Print the result of 3 calls to Adder's `add(int,int)` method as 3
		// space-separated integers:
		System.out.print(a.add(10, 32) + " " + a.add(10, 3) + " " + a.add(10, 10) + "\n");
	}
}
