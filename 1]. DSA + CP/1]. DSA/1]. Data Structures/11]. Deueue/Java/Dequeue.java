import java.util.LinkedList;
import java.util.List;

public class Dequeue<T> {
    private static class DequeueException extends RuntimeException {
        public DequeueException(String message) {
            super(message);
        }
    }

    private List<T> list;

    public Dequeue() {
        this.list = new LinkedList<>();
    }

    public void addFirst(T e) {
        list.add(0, e);
    }

    public void addLast(T e) {
        list.add(e);
    }

    public T getFirst() {
        if (list.size() == 0) throw new DequeueException("Empty Dequeue");
        return list.get(0);
    }

    public T getLast() {
        if (list.size() == 0) throw new DequeueException("Empty Dequeue");
        return list.get(list.size() - 1);
    }

    public T removeFirst() {
        if (list.size() == 0) throw new DequeueException("Empty Dequeue");
        return list.remove(0);
    }

    public T removeLast() {
        if (list.size() == 0) throw new DequeueException("Empty Dequeue");
        return list.remove(list.size() - 1);
    }

    public int size() {
        return list.size();
    }

    @Override
    public String toString() {
        return list.toString();
    }

    public static void main(String[] args) {
        Dequeue<String> q=new Dequeue<>();
        q.addFirst("Nisab");
        q.addFirst("Hello");
        q.addLast("Welcome");
        q.addLast("Home");
        System.out.println(q.size());
        System.out.println(q);
        System.out.println(q.removeFirst());
        System.out.println(q.getFirst());
        System.out.println(q.removeLast());
        System.out.println(q.getLast());
    }
}
