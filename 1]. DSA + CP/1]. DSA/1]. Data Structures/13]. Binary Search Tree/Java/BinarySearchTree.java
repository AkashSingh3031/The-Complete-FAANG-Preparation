import java.util.*;

class BinaryTree {
    public static class TreeNode<T extends Comparable<T>> implements Comparable<T> {

        T val;
        TreeNode left, right;

        public TreeNode() {
        }

        public TreeNode(T val) {
            this.val = val;
        }

        public TreeNode(T val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(T o) {
            return this.val.compareTo(o);
        }

    }

    public List<Object> inOrder(TreeNode node) {
        if (node == null) {
            return new ArrayList<>();
        }
        List<Object> list = new ArrayList<>();
        list.addAll(inOrder(node.left));
        list.add(node.val);
        list.addAll(inOrder(node.right));
        return list;
    }

    public List<Object> preOrder(TreeNode node) {
        if (node == null) {
            return new ArrayList<>();
        }
        List<Object> list = new ArrayList<>();
        list.add(node.val);
        list.addAll(preOrder(node.left));
        list.addAll(preOrder(node.right));
        return list;
    }

    public List<Object> postOrder(TreeNode node) {
        if (node == null) {
            return new ArrayList<>();
        }
        List<Object> list = new ArrayList<>();
        list.addAll(postOrder(node.left));
        list.addAll(postOrder(node.right));
        list.add(node.val);
        return list;
    }

    public List<List<Object>> levelOrder(TreeNode node) {
        Map<Integer, List<Object>> map = new LinkedHashMap<>();
        helper(node, map, 0);
        List<List<Object>> list = new ArrayList<>();
        map.forEach((k, v) -> {
            list.add(v);
        });
        return list;
    }

    private void helper(TreeNode node, Map<Integer, List<Object>> map, int level) {
        if (node == null) {
            return;
        }
        if (map.containsKey(level)) {
            map.get(level).add(node.val);
        } else {
            map.put(level, new ArrayList<>(Arrays.asList(node.val)));
        }
        helper(node.left, map, level + 1);
        helper(node.right, map, level + 1);
    }

    public List<Object> leftView(TreeNode node) {
        Map<Integer, Object> map = new LinkedHashMap<>();
        helperLeftOrRightView(node, map, 0, true);
        List<Object> list = new ArrayList<>();
        map.forEach((k, v) -> {
            list.add(v);
        });
        return list;
    }

    private void helperLeftOrRightView(TreeNode node, Map<Integer, Object> map, int level, boolean left) {
        if (node == null) {
            return;
        }
        if (left) {
            if (!map.containsKey(level)) {
                map.put(level, node.val);
            }
        } else {
            map.put(level, node.val);
        }
        helperLeftOrRightView(node.left, map, level + 1, left);
        helperLeftOrRightView(node.right, map, level + 1, left);
    }

    public List<Object> rightView(TreeNode node) {
        Map<Integer, Object> map = new LinkedHashMap<>();
        helperLeftOrRightView(node, map, 0, false);
        List<Object> list = new ArrayList<>();
        map.forEach((k, v) -> {
            list.add(v);
        });
        return list;
    }

    private static class Pair<K, V> {

        K key;
        V val;

        public Pair(K key, V val) {
            this.key = key;
            this.val = val;
        }

    }

    public List<Object> topView(TreeNode node) {
        List<Object> list = new ArrayList<>();
        Map<Integer, Object> map = new TreeMap<>();
        if (node == null) {
            return list;
        }
        Queue<Pair<Integer, TreeNode>> queue = new LinkedList<>();
        queue.add(new Pair<>(0, node));
        while (!queue.isEmpty()) {
            Pair<Integer, TreeNode> temp = queue.poll();
            if (!map.containsKey(temp.key)) {
                map.put(temp.key, temp.val.val);
            }
            if (temp.val.left != null) {
                queue.add(new Pair<>(temp.key - 1, temp.val.left));
            }
            if (temp.val.right != null) {
                queue.add(new Pair<>(temp.key + 1, temp.val.right));
            }
        }
        map.forEach((k, v) -> {
            list.add(v);
        });
        return list;
    }

    public List<Object> bottomView(TreeNode node) {
        List<Object> list = new ArrayList<>();
        Map<Integer, Object> map = new TreeMap<>();
        if (node == null) {
            return list;
        }
        Queue<Pair<Integer, TreeNode>> queue = new LinkedList<>();
        queue.add(new Pair<>(0, node));
        while (!queue.isEmpty()) {
            Pair<Integer, TreeNode> temp = queue.poll();
            map.put(temp.key, temp.val.val);
            if (temp.val.left != null) {
                queue.add(new Pair<>(temp.key - 1, temp.val.left));
            }
            if (temp.val.right != null) {
                queue.add(new Pair<>(temp.key + 1, temp.val.right));
            }
        }
        map.forEach((k, v) -> {
            list.add(v);
        });
        return list;
    }

    private int c = 0;

    public int size(TreeNode node) {
        c = 0;
        count(node);
        return c;
    }

    private void count(TreeNode node) {
        if (node == null) {
            return;
        }
        c++;
        count(node.left);
        count(node.right);
        return;

    }

    public int height(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return Math.max(height(node.left), height(node.right)) + 1;
    }
}

public class BinarySearchTree<T extends Comparable<T>> extends BinaryTree {


    private TreeNode<T> root;
    private int size = 0;

    public BinarySearchTree() {
        root = null;
        size = 0;
    }

    public void add(T val) {
        root = add(val, root);
    }

    private TreeNode add(T val, TreeNode node) {
        if (node == null) {
            size++;
            return new TreeNode<>(val);
        }
        if (node.compareTo(val) > 0) {
            node.left = add(val, node.left);
        } else if (node.compareTo(val) < 0) {
            node.right = add(val, node.right);
        }
        return node;
    }

    public List<Object> inOrder() {
        return super.inOrder(root);
    }

    public List<Object> preOrder() {
        return super.preOrder(root);
    }

    public List<Object> postOrder() {
        return super.postOrder(root);
    }

    private static boolean that = false;

    public void remove(T val) {
        that = false;
        root = remove(val, root);
        if (that) {
            size++;
        }
    }

    private TreeNode remove(T val, TreeNode node) {
        if (node == null) {
            return null;
        }
        if (node.compareTo(val) > 0) {
            node.left = remove(val, node.left);
        } else if (node.compareTo(val) < 0) {
            node.right = remove(val, node.right);
        } else {
            if (node.left == null && node.right != null) {
                size--;
                return node.right;
            } else if (node.right == null && node.left != null) {
                size--;
                return node.left;
            } else if (node.right != null && node.left != null) {
                T temp = getMin(node.right);
                node.val = temp;
                node.right = remove(temp, node.right);
                that = true;
                size--;
                return node;
            } else {
                size--;
                return null;
            }

        }
        return node;
    }

    private T getMin(TreeNode node) {
        if (node.left == null) {
            return (T) node.val;
        }
        return getMin(node.left);
    }

    public T getMin() {
        return getMin(root);
    }

    public boolean contains(T val) {
        return contains(val, root);
    }

    private boolean contains(T val, TreeNode node) {
        if (node == null) {
            return false;
        }
        if (node.compareTo(val) == 0) {
            return true;
        }
        return contains(val, node.left) || contains(val, node.right);
    }

    public List<List<Object>> levelOrder() {
        return super.levelOrder(root);
    }

    public List<Object> leftView() {
        return super.leftView(root);
    }

    public List<Object> rightView() {
        return super.rightView(root);
    }

    public int size() {
        return size;
    }

    public List<Object> topView() {
        return super.topView(root);
    }

    public List<Object> bottomView() {
        return super.bottomView(root);
    }

    public int height() {
        return super.height(root);
    }

    public void clear() {
        root = null;
    }

    @Override
    public String toString() {
        return this.inOrder().toString();
    }


    public static void main(String[] args) {
        BinarySearchTree<Integer> tree = new BinarySearchTree<>();
        tree.add(45);
        tree.add(95);
        tree.add(99);
        tree.add(47);
        tree.add(587);
        tree.add(147);
        tree.add(2);
        System.out.println(tree.size());
        System.out.println(tree.height());
        System.out.println(tree.inOrder());
        System.out.println(tree.preOrder());
        System.out.println(tree.postOrder());
        System.out.println(tree.levelOrder());
        System.out.println(tree.contains(95));
        System.out.println(tree.bottomView());
        System.out.println(tree.topView());
        System.out.println(tree.leftView());
        System.out.println(tree.rightView());
        tree.remove(95);
        System.out.println(tree.inOrder()); // after removed 95 traverse

    }
}
