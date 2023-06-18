public class DoubleLinkedList<T> {

    private class Node<T> {
        T val;
        Node<T> prev, next;

        public Node(T val) {
            this.val = val;
        }

        public Node(T val, Node<T> prev, Node<T> next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }

    private Node<T> head, tail;
    private int size;

    public DoubleLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public boolean add(T val) {
        Node<T> node = new Node<>(val);
        if (head == null) {
            head = node;
            tail = node;
            size++;
            return true;
        }
        node.prev = tail;
        tail.next = node;
        tail = tail.next;
        size++;
        return true;
    }

    public void add(int index, T val) {
        if (index > size) return;
        if (index == 0) {
            addFirst(val);
            return;
        }
        if (index == size) {
            addLast(val);
            return;
        }
        Node<T> t = head;
        while (index > 1) {
            index--;
            t = t.next;
        }
        Node node = new Node<>(val, t, t.next);
        t.next.prev = node;
        t.next = node;
        size++;
    }

    public void addFirst(T val) {
        if (head == null) {
            this.add(val);
            return;
        }
        Node<T> node = new Node<>(val);
        node.next = head;
        head.prev = node;
        head = node;
        size++;
    }

    public void addLast(T val) {
        this.add(val);
    }

    public void clear() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public boolean contains(T val) {
        Node<T> t = head;
        while (t != null) {
            if (val.equals(t.val)) return true;
            t = t.next;
        }
        return false;
    }

    public T get(int index) {
        if (index > size) return null;
        Node<T> t = head;
        while (index > 0) {
            t = t.next;
            index--;
        }
        return t.val;
    }

    public int indexOf(T val) {
        int index = 0;
        Node<T> t = head;
        while (index < size && t.next != null) {
            if (t.val.equals(val)) return index;
            t = t.next;
            index++;
        }
        return -1;
    }

    public T removeFirst() {
        if (head == null) return null;
        if (head.next == null) {
            T val = head.val;
            head = null;
            tail = null;
            size--;
            return val;
        }
        T val = head.val;
        head = head.next;
        head.prev = null;
        size--;
        return val;
    }

    public T removeLast() {
        if (tail == null) return null;
        if (head == tail) {
            T val = head.val;
            head = null;
            tail = null;
            size--;
            return val;
        }
        T val = tail.val;
        tail=tail.prev;
        tail.next = null;
        size--;
        return val;
    }


    public T remove(int index) {
        if (index > size) return null;
        Node<T> t = head;
        while (index > 0) {
            t = t.next;
            index--;
        }
        T val = t.val;
        t.prev.next = t.next;
        t.next.prev = t.prev;
        t.next = null;
        t.prev = null;
        size--;
        return val;
    }

    public T set(int index, T val) {
        if (index > size) return null;
        Node<T> t = head;
        while (index > 0) {
            t = t.next;
            index--;
        }
        t.val = val;
        return t.val;
    }

    public int size() {
        return this.size;
    }

    public String toString() {
        StringBuilder b = new StringBuilder("[");
        Node<T> t = head;
        if (t == null) return b.append("]").toString();
        while (t != null) {
            b.append(t.val + ",");
            t = t.next;
        }
        b.deleteCharAt(b.length() - 1).append("]");
        return b.toString();
    }

    public String toStringReversed() {
        StringBuilder b = new StringBuilder("[");
        Node<T> t = tail;
        if (t == null) return b.append("]").toString();
        while (t != null) {
            b.append(t.val + ",");
            t = t.prev;
        }
        b.deleteCharAt(b.length() - 1).append("]");
        return b.toString();
    }

    public static void main(String[] args) {
        DoubleLinkedList<Integer> list = new DoubleLinkedList<>();
        list.add(99);
        list.add(45);
        list.add(98);
        list.add(47);
        list.add(1, 69);
        list.add(0, 2);
        list.add(6, 66);
        System.out.println(list.size());
        list.addFirst(12);
        list.addLast(33);
        System.out.println(list.size());
        System.out.println(list);
        System.out.println(list.get(6));
        System.out.println(list.contains(45));
        System.out.println(list.contains(1));
        list.set(4, 74);
        System.out.println(list.indexOf(99));
        System.out.println(list.indexOf(76));
        System.out.println(list);
        list.removeFirst();
        list.removeLast();
        System.out.println(list);
        list.remove(2);
        System.out.println(list);
        System.out.println(list.toStringReversed());
    }
}
