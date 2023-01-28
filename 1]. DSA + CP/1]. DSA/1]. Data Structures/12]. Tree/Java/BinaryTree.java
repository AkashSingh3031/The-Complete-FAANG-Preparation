
import java.util.*;
public class BinaryTree  {
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

    public  List<Object> inOrder(TreeNode node) {
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

    public static void main(String[] args) {
        TreeNode<Integer> root = new TreeNode<>(99);
        TreeNode<Integer> left1 = new TreeNode<>(45);
        TreeNode<Integer> left2 = new TreeNode<>(12);
        TreeNode<Integer> left3 = new TreeNode<>(98);
        TreeNode<Integer> right1 = new TreeNode<>(109);
        TreeNode<Integer> rightleft1 = new TreeNode<>(55);
        root.left = left1;
        root.left.left = left2;
        root.left.right = rightleft1;
        root.left.left.left = left3;
        root.right = right1;

        BinaryTree tree = new BinaryTree();
        System.out.println(tree.height(root));
        System.out.println(tree.inOrder(root));
        System.out.println(tree.preOrder(root));
        System.out.println(tree.postOrder(root));
        System.out.println(tree.levelOrder(root));
        System.out.println(tree.bottomView(root));
        System.out.println(tree.topView(root));
        System.out.println(tree.leftView(root));
        System.out.println(tree.rightView(root));
    }
}
