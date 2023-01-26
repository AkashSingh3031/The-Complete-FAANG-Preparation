public class Main {

    public static void main(String[] args) throws Exception {
        StackCustom<Integer> stack = new StackCustom<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println(stack);
        while(!stack.empty()){
            System.out.println(stack.pop());
        }

    }
}
