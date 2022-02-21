/**
 * 
 */ 
/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 *
 */

class Sports {

	String getName() {
		return "Generic Sports";
	}

	 // Write your overridden getNumberOfTeamMembers method here
	void getNumberOfTeamMembers() {
		System.out.println("Each team has n players in " + getName());
	}
}

class Soccer extends Sports {
	@Override
	String getName() {
		return "Soccer Class";
	}

}

public class JavaMethodOverriding {
	public static void main(String[] args) {
		Sports c1 = new Sports();
		Soccer c2 = new Soccer();
		System.out.println(c1.getName());
		c1.getNumberOfTeamMembers();
		System.out.println(c2.getName());
		c2.getNumberOfTeamMembers();
	}
}
