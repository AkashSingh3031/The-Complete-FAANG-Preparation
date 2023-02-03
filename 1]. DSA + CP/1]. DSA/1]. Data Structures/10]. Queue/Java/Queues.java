import java.util.*;

public class Queues<T> {


    private List<T> list;

    public Queues() {
        list = new LinkedList<>();
    }

    public int size() {
        return list.size();
    }

    public boolean add(T val) {
        return list.add(val);
    }

    public T remove() {
        if (list.size() == 0) throw new QueueException("Empty Queue");
        return list.remove(0);
    }

    public T peek() {
        if (list.size() == 0) throw new QueueException("Empty Queue");
        return list.get(0);
    }

    @Override
    public String toString() {
        return list.toString();
    }

    private static class QueueException extends RuntimeException {
        public QueueException(String message) {
            super(message);
        }
    }

    public static void main(String[] args) {
        Queues<Integer> q = new Queues<>();
        q.add(45);
        q.add(99);
        q.add(12);
        q.add(55);
        System.out.println(q.size());
        System.out.println(q);
        System.out.println(q.peek());
        while (q.size() != 0) {
            System.out.println(q.remove());
        }
        try {
            System.out.println(q.remove()); // empty queue remove exception thrown
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
