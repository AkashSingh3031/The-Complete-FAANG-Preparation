public class Main {
    public static void main(String[] args) {
        Trie trie=new Trie();
        trie.add("app");
        trie.add("apple");
        trie.add("bye");
        trie.add("by");
        trie.add("apply");
        trie.remove("apple");
        System.out.println(trie.contains("apple"));
        System.out.println(trie.contains("app"));
        System.out.println(trie.contains("apply"));

    }
}
