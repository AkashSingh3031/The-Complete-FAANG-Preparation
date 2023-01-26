public class StackCustom<T> {

    private Object[] arr;
    private int top = -1, size = 0;
    private final int DEFAULT_CAPACITY = 5;
    private boolean expand = false;

    public StackCustom() {
        arr = new Object[DEFAULT_CAPACITY];
        expand = true;
    }

    public StackCustom(int initailCapacity) {
        arr = new Object[initailCapacity];
    }

    private void doubleArr() {
        Object[] temp = new Object[2 * arr.length];
        for (int i = 0; i < arr.length; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
    }

    public T push(T val) throws Exception {
        if (top == arr.length - 1) {
            if (expand) {
                doubleArr();
            } else {
                throw new Exception("Stack Overflow");
            }
        }
        arr[++top] = val;
        return (T) arr[top];

    }

    public boolean empty() {
        return top == -1;
    }

    public T peek() throws Exception {
        if (top == -1) {
            throw new Exception("Empty stack exception");
        }
        return (T) arr[top];
    }

    public T pop() throws Exception {
        if (top == -1) {
            throw new Exception("Empty stack exception");
        }
        T temp = (T) arr[top];
        top--;
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

}
