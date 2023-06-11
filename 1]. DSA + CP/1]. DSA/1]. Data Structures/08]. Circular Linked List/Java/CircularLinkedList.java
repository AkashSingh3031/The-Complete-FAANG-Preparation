public class CircularLinkedList<T> {

    private class Node<T> {
        T val;
        Node<T> next;

        public Node(T val) {
            this.val = val;
            this.next = null;
        }

        public Node(T val, Node<T> next) {
            this.val = val;
            this.next = next;
        }
    }

    private Node<T> head, tail;
    private int size;

    public CircularLinkedList() {
        this.head = null;
        this.size = 0;
    }

    public boolean add(T val) {
        Node<T> node = new Node<>(val);
        if (head == null) {
            head = node;
            tail = head;
            size++;
            return true;
        }
        tail.next = node;
        tail = node;
        node.next = head;
        size++;
        return false;
    }

    public void add(int index, T val) {
        if (index > size || index < 0) {
            throw new RuntimeException("Index out of bound exception");
        }
        Node<T> node = new Node<>(val);
        Node<T> temp = head;
        if (temp == null) {
            this.add(val);
        } else {
            if (index == 0) {
                tail.next = node;
                node.next = head;
                head = node;
            } else {
                if (index == size) {
                    this.add(val);
                } else {
                    while (index < 1) {
                        temp = temp.next;
                        index--;
                    }
                    node.next = temp.next;
                    temp.next = node;
                }

            }
            size++;
        }
    }

    public void clear() {
        this.head = null;
        this.size = 0;
        this.tail = null;
    }

    public T getFirst() {
        return this.head == null ? null : this.head.val;
    }

    public T getLast() {
        return this.tail == null ? null : this.tail.val;
    }

    public int size() {
        return this.size;
    }

    public T set(int index, T val) {
        if (index >= size || index < 0) return null;
        Node<T> temp = head;
        while (index != 0) {
            index--;
            temp = temp.next;
        }
        temp.val = val;
        return temp.val;
    }

    public T get(int index) {
        if (index >= size || index < 0) return null;
        Node<T> temp = head;
        while (index != 0) {
            index--;
            temp = temp.next;
        }
        return temp.val;
    }

    public T remove(int index) {
        if (index >= size || index < 0) return null;
        Node<T> t = head;
        if (index == 0) {
            tail.next = head.next;
            head = head.next;
            return t.val;
        } else {
            while (index > 1) {
                t = t.next;
                index--;
            }
            T v = t.next.val;
            t.next = t.next.next;
            return v;
        }
    }

    public boolean contains(T val) {
        Node<T> temp = head;
        while (temp.val != val && temp.next != head) {
            temp = temp.next;
        }
        if (temp.val == val) return true;
        return false;
    }

    public int indexOf(T val) {
        int t = 0;
        Node<T> temp = head;
        while (temp.val != val && temp.next != head) {
            t++;
            temp = temp.next;
        }
        if (temp.val == val) return t;
        return -1;
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder();
        b.append("[");
        Node<T> t = head;
        if (t == null) {
            return b.append("]").toString();
        }
        do {
            b.append(t.val + ",");
            t = t.next;
        }
        while (t != head);
        b.append("]");
        return b.toString();
    }

    public static void main(String[] args) {
        CircularLinkedList<Integer> list = new CircularLinkedList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(0, 78);
        list.add(4, 99);
        System.out.println(list.indexOf(99));
        System.out.println(list.indexOf(45));
        System.out.println(list.contains(45));
        System.out.println(list.contains(99));
        list.set(0,45);
        System.out.println(list.contains(45));
        System.out.println(list.get(4));
        System.out.println(list.size());
        System.out.println(list.getFirst());
        System.out.println(list.getLast());
        System.out.println(list);
        list.remove(0);
        System.out.println(list);
        list.remove(2);
        System.out.println(list);
        list.remove(6);
        System.out.println(list);
    }
}
