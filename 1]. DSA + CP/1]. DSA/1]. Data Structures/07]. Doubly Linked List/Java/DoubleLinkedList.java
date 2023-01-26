import java.util.Collection;

public class DoubleLinkedList<T> {

    private Node head, tail;
    private int size = 0;

    private class Node<T> {

        T val;
        Node prev;
        Node next;

        public Node(T val, Node prev, Node next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public void clear() {
        size = 0;
        head = null;
        tail = head;
    }

    public boolean add(T val) {
        if (head == null) {
            head = new Node(val, null, null);
            tail = head;
            size++;
            return true;
        }
        tail.next = new Node(val, tail, tail.next);
        tail = tail.next;
        size++;
        return tail.val.equals(val);
    }

    public boolean addAll(Collection<? extends T> c) {
        int prevSize = size();
        c.forEach(elem -> add(elem));
        return size() - prevSize == c.size();
    }

    public boolean contains(T val) {
        Node temp = head;
        while (temp != null) {
            if (temp.val.equals(val)) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    public boolean add(int index, T val) throws Exception {
        if (index > size) {
            throw new Exception("No such index found exception");
        }
        if (index == 0) {
            Node node = new Node(val, null, head);
            head = node;
            size++;
            return true;
        }
        if (index == size) {
            add(val);
            return true;
        }
        Node temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp.next;
        }
        Node node = new Node(val, temp, temp.next);
        temp.next = node;
        size++;
        return true;
    }

    public T set(int index, T val) throws Exception {
        if (index >= size) {
            throw new Exception("No such index found exception");
        }
        Node temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        temp.val = val;
        return (T) temp.val;
    }

    public T get(int index) throws Exception {
        if (index > size - 1) {
            throw new Exception("No such index found exception");
        }
        Node temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return (T) temp.val;
    }

    public T remove(int index) throws Exception {
        if (index > size - 1) {
            throw new RuntimeException("No such index found exception");
        }
        Node temp = head;
        if (index == 0) {
            T ret = (T) head.val;
            head = head.next;
            head.prev = null;
            size--;
            return ret;
        }
        if (index == size - 1) {
            T ret = (T) tail.val;
            tail = tail.prev;
            tail.next = null;
            size--;
            return ret;
        }
        for (int i = 1; i < index; i++) {
            temp = temp.next;
        }
        T ret = (T) temp.next.val;
        temp.next.next.prev = temp;
        temp.next = temp.next.next;
        size--;
        return ret;
    }

    @Override
    public String toString() {
        StringBuilder ret = new StringBuilder("[");
        Node temp = head;
        if (temp == null) {
            ret.append("]");
            return ret.toString();
        }
        while (temp.next != null) {
            ret.append(temp.val + ",");
            temp = temp.next;
        }
        ret.append(temp.val + "]");
        return ret.toString();
    }

    public String reverseToString() {
        String ret = "[";
        Node temp = tail;
        if (temp == null) {
            ret += "]";
            return ret;
        }
        while (temp.prev != null) {
            ret += temp.val + ",";
            temp = temp.prev;
        }
        ret += temp.val + "]";
        return ret;
    }

}
