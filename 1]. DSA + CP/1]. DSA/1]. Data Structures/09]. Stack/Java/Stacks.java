public class Stacks<T> {

    private Object[] arr;
    private int top = -1;
    private final int DEFAULT_CAPACITY = 5;
    private boolean expand = false;

    public Stacks() {
        // this creates a dynamic stack with no length bound
        arr = new Object[DEFAULT_CAPACITY];
        expand = true;
    }

    public Stacks(int capacity) {
        // this creates capacity bounded stack
        arr = new Object[capacity];
    }

    private void doubleArr() {
        // this method used internally for dynamic length of stack
        Object[] temp = new Object[2 * arr.length];
        for (int i = 0; i < arr.length; i++)
            temp[i] = arr[i];
        arr = temp;
    }

    public T push(T val) throws RuntimeException {
        if (top == arr.length - 1) {
            if (expand) doubleArr();
            else throw new RuntimeException("Stack Overflow");
        }
        arr[++top] = val;
        return (T) arr[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int size() {
        return this.top+1;
    }

    public T peek() throws RuntimeException {
        if (top == -1)  throw new RuntimeException("Empty stack exception");
        return (T) arr[top];
    }

    public T pop() throws RuntimeException {
        if (top == -1)   throw new RuntimeException("Empty stack exception");
        T temp = (T) arr[top--];
        return temp;
    }

    @Override
    public String toString() {
        StringBuilder ret = new StringBuilder("[");
        int i = 0;
        for (; i < top; i++) {
            ret.append(arr[i] + ",");
        }
        if (arr[i] != null) {
            ret.append(arr[i] + "]");
        } else {
            ret.append("]");
        }
        return ret.toString();
    }

    public static void main(String[] args) {
        Stacks<String> stack=new Stacks<>();
        stack.push("Hello");
        stack.push("Welcome");
        stack.push("To");
        stack.push("DataStructure");
        System.out.println(stack.size());
        System.out.println(stack);
        while(!stack.isEmpty()){
            System.out.println(stack.pop());
        }
       // System.out.println(stack.pop());  Empty stack exception
        System.out.println(stack.isEmpty());
        System.out.println(stack.size());

    }
}
