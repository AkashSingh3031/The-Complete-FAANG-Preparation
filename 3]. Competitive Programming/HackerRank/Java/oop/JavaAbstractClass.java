/**
 * Solution forhttps://www.hackerrank.com/challenges/java-abstract-class
 */


import java.util.Scanner;

/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 *
 */
abstract class Book {
	String title;

	abstract void setTitle(String s);

	String getTitle() {
		return title;
	}
}

// Write MyBook class here
class MyBook extends Book {

	void setTitle(String s) {
		super.title = s;
	}
}

public class JavaAbstractClass {
	public static void main(String[] args) {
		// Book new_novel=new Book(); This line prHMain.java:25: error: Book is
		// abstract; cannot be instantiated
		Scanner sc = new Scanner(System.in);
		String title = sc.nextLine();
		MyBook new_novel = new MyBook();
		new_novel.setTitle(title);
		System.out.println("The title is: " + new_novel.getTitle());
		sc.close();

	}
}