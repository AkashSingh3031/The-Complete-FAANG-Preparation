import java.util.*;

public class Trie {
// Also known as Prefix Tree

    private TrieNode root;

    // private class inorder to acheive abstarct data structure
    private class TrieNode {

        HashMap<Character, TrieNode> map; // A HashMap for character referring to another TrieNode
        boolean isEndOfWord; //Used inorder to know the word end

        public TrieNode(HashMap<Character, TrieNode> map, boolean isEndOfWord) {
            this.map = map;
            this.isEndOfWord = isEndOfWord;
        }

        public TrieNode() {
            this.map = new HashMap<>();
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            builder.append(this.map);
            builder.append(this.isEndOfWord);
            return builder.toString();
        }

    }

    // Trie Constructor
    public Trie() {
        this.root = new TrieNode();
        this.root.isEndOfWord = false;
    }

    // Adds a specied String in Trie
    public boolean add(String o) {
        return this.add(o, root);
    }

    // Private helper add
    /*
        Adding happens as taking each character and corresponds a node so that it means the character is present
        And when all characters gets added the last character node to which its pointing there isEndOfWord becomes true, To indiacte this path follows a String
     */
    private boolean add(String str, TrieNode node) {
        TrieNode temp = node;
        for (int i = 0; i < str.length(); i++) {
            if (temp.map.containsKey(str.charAt(i))) {
                temp = temp.map.get(str.charAt(i));
            } else {
                temp.map.put(str.charAt(i), new TrieNode());
                temp = temp.map.get(str.charAt(i));
            }
        }
        temp.isEndOfWord = true;
        return true;
    }

    // To check whether a string is present or not
    public boolean contains(String o) {
        return this.contains(o, root);
    }

    // Contains private helper method
    private boolean contains(String str, TrieNode node) {
        TrieNode temp = node;
        for (int i = 0; i < str.length(); i++) {
            if (!temp.map.containsKey(str.charAt(i))) {
                return false;
            } else {
                temp = temp.map.get(str.charAt(i));
            }
        }
        return temp.isEndOfWord;
    }

    // Clears the Trie
    public void clear() {
        this.root = new TrieNode();
    }

    // Remove a Specified String from Trie
    /*
        Deletion or removal of a string from Trie does not mean you destruct or remove complete path from Trie
        Beacuse There may be another string follwing same path inorder to form their own word
        Hence we traverse the path of String in Trie and marks the last character node which its pointing to isEndOfWord to false
        Eg: "apply" and "app" follows same path hence removal of "apple" path will leads in deletion of "app" too.
     */
    public void remove(String o) {
        TrieNode node = root;
        for (int i = 0; i < o.length(); i++) {
            if (node.map.containsKey(o.charAt(i))) {
                node = node.map.get(o.charAt(i));
            } else {
                return;
            }
        }
        node.isEndOfWord = false;
    }

    // When print is done to Trie toString metod is called
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        TrieNode node = root;
        builder.append(node);
        return builder.toString();
    }

    
    // Main function
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
