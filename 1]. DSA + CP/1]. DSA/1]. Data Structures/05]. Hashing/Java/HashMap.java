import java.util.Objects;
import java.util.function.BiConsumer;

public class HashMap<K, V> {
    private final int DEFAULT_CAPACITY = 17;
    private final Entry[] bucket = new Entry[DEFAULT_CAPACITY];
    private int size = 0;

    private class Entry<K, V> {

        K key;
        V val;
        Entry next;

        public Entry(K key, V val, Entry next) {
            this.key = key;
            this.val = val;
            this.next = next;
        }

    }

    private int hashCode(K key) {
        return key.hashCode() % bucket.length;
    }

    public boolean put(K key, V val) {
        int hash = hashCode(key);
        if (bucket[hash] == null) {
            bucket[hash] = new Entry(key, val, null);
            size++;
            return true;
        }
        Entry temp = bucket[hash];
        if (temp.key.equals(key)) {
            temp.val = val;
            return true;
        }
        while (temp.next != null) {
            if (temp.key.equals(key)) {
                temp.val = val;
                return true;
            }
            temp = temp.next;
        }
        size++;
        temp.next = new Entry(key, val, null);
        return true;
    }

    public V get(K key) {
        int hash = hashCode(key);
        Entry temp = bucket[hash];
        while (temp != null) {
            if (temp.key.equals(key)) {
                return (V) temp.val;
            }
            temp = temp.next;
        }
        return null;
    }

    public boolean containsKey(K key) {
        return get(key) != null;
    }

    public boolean containsValue(V val) {
        for (int i = 0; i < bucket.length; i++) {
            Entry temp = bucket[i];
            while (temp != null) {
                if (temp.val.equals(val)) {
                    return true;
                }
                temp = temp.next;
            }
        }
        return false;
    }

    public V remove(K key) throws RuntimeException {
        int hash = hashCode(key);
        Entry temp = bucket[hash];
        if (temp == null) {
            throw new RuntimeException("No such element exception");
        }
        if (temp.key.equals(key)) {
            V retval = (V) bucket[hash].val;
            bucket[hash] = temp.next;
            size--;
            return retval;
        }
        while (temp.next != null) {
            if (temp.next.key.equals(key)) {
                break;
            }
            temp = temp.next;
        }
        if (temp.next == null) {
            throw new RuntimeException("No such element exception");
        }
        V retval = (V) temp.next.val;
        temp.next = temp.next.next;
        size--;
        return retval;
    }

    public V getOrDefault(K key, V defaultValue) {
        V value = get(key);
        if (value != null) {
            return value;
        }
        return defaultValue;
    }

    public void clear() {
        for (int i = 0; i < bucket.length; i++) {
            bucket[i] = null;
        }
    }

    // forEach method takes BiConsumer<K,V>
    public void forEach(BiConsumer<K, V> o) {
        Objects.requireNonNull(o);
        for (int i = 0; i < bucket.length; i++) {
            Entry temp = bucket[i];
            while (temp != null) {
                o.accept((K) temp.key, (V) temp.val);
                temp = temp.next;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("{");
        for (int i = 0; i < bucket.length; i++) {
            Entry temp = bucket[i];
            while (temp != null) {
                builder.append(temp.key + "=" + temp.val + ",");
                temp = temp.next;
            }
        }
        if (builder.length() == 1) builder.append(" ");
        String t = builder.substring(0, builder.length() - 1);
        return (new StringBuilder(t)).append("}").toString();
    }

    public int size() {
        return size;
    }

    public Object[] toKeyArray() {
        Object[] t = new Object[size()];
        int j = 0;
        for (int i = 0; i < bucket.length; i++) {
            Entry temp = bucket[i];
            while (temp != null) {
                t[j++] = temp.key;
                temp = temp.next;
            }
        }
        return t;
    }

    public static void main(String[] args) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(1, 45);
        map.put(2, 990);
        map.put(55, 76);
        System.out.println(map);
        System.out.println(map.get(1)); // 45
        System.out.println(map.get(99)); // null
        System.out.println(map.getOrDefault(99, 0)); //0
        System.out.println(map.containsKey(1));
        System.out.println(map.containsValue(45));
        map.remove(1);
        System.out.println(map.containsKey(1)); // false
        map.forEach((k,v)->{
            System.out.println(k+" -> "+v);
        });

    }
}
