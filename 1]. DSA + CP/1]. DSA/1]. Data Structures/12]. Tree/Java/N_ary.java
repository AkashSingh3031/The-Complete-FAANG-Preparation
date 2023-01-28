import java.util.*;

public class N_ary<E> {

    public class Node<T extends E> {

        T val;
        ArrayList<Node> list;

        public Node(T val, ArrayList<Node> list) {
            this.val = val;
            this.list = list;
        }

    }

    public List<E> preOrder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<E> ans = new ArrayList<>();
        ans.add((E) root.val);
        root.list.forEach(item -> {
            ans.addAll(preOrder((Node) item));
        });
        return ans;
    }

    public List<E> postOrder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<E> ans = new ArrayList<>();
        root.list.forEach((item) -> {
            ans.addAll(postOrder((Node) item));
        });
        ans.add((E) root.val);
        return ans;
    }

    public static void main(String[] args) {
        N_ary<Integer> tree = new N_ary<>();
        N_ary.Node node4 = tree.new Node<Integer>(5, new ArrayList<>());
        N_ary.Node node5 = tree.new Node<Integer>(6, new ArrayList<>());
        N_ary.Node node1 = tree.new Node<Integer>(3, new ArrayList<>(Arrays.asList(node4, node5)));
        N_ary.Node node2 = tree.new Node<Integer>(2, new ArrayList<>());
        N_ary.Node node3 = tree.new Node<Integer>(4, new ArrayList<>());
        N_ary.Node root = tree.new Node<Integer>(1, new ArrayList<>(Arrays.asList(node1, node2, node3)));
        System.out.println(tree.preOrder(root));
        System.out.println(tree.postOrder(root));

    }
}
