import java.util.ArrayList;
import java.util.Comparator;

public class Heap<T extends Comparable<T>> {

    private ArrayList<T> list = new ArrayList<>();
    private int index;

    private int size = 0;

    // Default as maxheap
    public Heap() {
        list.add(null);
        index = 0;
    }

    // pass Comparator for min Heap
    // pass  Comparator.reverseOrder() for min heap
    public Heap(Comparator<T> comparator) {
        this.comparator = comparator;
        list.add(null);
        index = 0;
    }

    public boolean add(T val) {
        return offer(val);
    }

    private Comparator<T> comparator = (o1, o2) -> {
        return o1.compareTo(o2);
    };

    public boolean offer(T val) {
        index++;
        size++;
        list.add(index, val);
        int i = index;
        while (i > 1) {
            int parentIndex = i / 2;
            if (comparator.compare(list.get(i), list.get(parentIndex)) > 0) {
                T t = list.get(i);
                list.set(i, list.get(parentIndex));
                list.set(parentIndex, t);
                i = parentIndex;
            } else {
                break;
            }
        }
        return true;
    }

    public T poll() {
        if (index == 0) {
            throw new RuntimeException("Empty Heap");
        }
        T deleted = list.get(1);
        T t = list.get(index);
        list.set(1, t);
        int i = 1;
        while (i < index - 1) {
            int maxIndex = i, left = 2 * i, right = (2 * i) + 1;
            if (left < index && comparator.compare(list.get(maxIndex), list.get(left)) < 0)
                maxIndex = left;
            if (right < index && comparator.compare(list.get(maxIndex), list.get(right)) < 0)
                maxIndex = right;
            if (maxIndex != i) {
                t = list.get(i);
                list.set(i, list.get(maxIndex));
                list.set(maxIndex, t);
                i = maxIndex;
            } else break;
        }
        index--;
        size--;
        return deleted;
    }

    public T peek() {
        if (index == 0) {
            throw new RuntimeException("Empty Heap");
        }
        return list.get(1);
    }

    public int size() {
        return size;
    }

    public void clear() {
        list.clear();
        index = 0;
    }

    public boolean isEmpty() {
        return index == 0;
    }

    @Override
    public String toString() {
        StringBuilder ans = new StringBuilder("[");
        if (list.size() == 1) return ans.append("]").toString();
        int i;
        for (i = 1; i < index; i++) {
            ans.append(list.get(i) + ", ");
        }
        ans.append(list.get(i));
        return ans.append("]").toString();
    }

    // Main function
    public static void main(String[] args) {
        Heap<Integer> heap = new Heap<>();
        heap.add(54);
        heap.add(24);
        heap.add(4);
        heap.add(99);
        heap.add(45);
        heap.add(93);
        System.out.println(heap);
        System.out.println(heap.size());
        while (!heap.isEmpty()) {
            System.out.println("polled -> " + heap.poll());
        }
        System.out.println(heap.size());
        try {
            heap.poll(); // trying to poll from empty heap throw exception empty heap
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        // Heap with other data type
        Heap<String> stringHeap = new Heap<>((a, b) -> a.compareTo(b));
        stringHeap.add("Nisab");
        stringHeap.add("Henry");
        stringHeap.add("Daisy");
        stringHeap.add("Akash");
        System.out.println(stringHeap);
        System.out.println(stringHeap.size());
        while (!stringHeap.isEmpty()) {
            System.out.println("polled -> " + stringHeap.poll());
        }
        System.out.println(stringHeap.size());

    }
}
