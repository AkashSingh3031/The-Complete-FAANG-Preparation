/**
 * Solution : https://www.hackerrank.com/challenges/java-inheritance-1
 */
/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 *
 */
class Animal{
	void walk(){
		System.out.println("I am walking");
	}
}


class Bird extends Animal{
	void fly(){
		System.out.println("I am flying");
	}
	//code need to be added
    void sing(){
        System.out.println("I am singing");
    }
}


public class JavaInheritanceI {
	public static void main(String args[]){

		  Bird bird = new Bird();
		  bird.walk();
		  bird.fly();
	      bird.sing();
		
	   }
	}
