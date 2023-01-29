class TrieNode {
  map: Map<string, TrieNode>;
  isEndOfWord: boolean;
  constructor() {
    this.map = new Map<string, TrieNode>();
    this.isEndOfWord = false;
  }
}

class Trie{
  private root: TrieNode;
  constructor() {
    this.root = new TrieNode();
  }
  add(word: string): boolean {
    let temp: TrieNode = this.root;
    for (let i = 0; i < word.length; i++) {
      if (!temp.map.has(word.charAt(i))) {
        temp.map.set(word.charAt(i), new TrieNode());
      }
      temp = temp.map.get(word.charAt(i))!;
    }
    temp.isEndOfWord = true;
    return temp.isEndOfWord;
  }
  delete(word: string): void {
    let temp: TrieNode = this.root;
    for (let i = 0; i < word.length; i++) {
      if (!temp.map.has(word.charAt(i))) return;
      temp = temp.map.get(word.charAt(i))!;
    }
    temp.isEndOfWord = false;
  }
  contains(word: string): boolean {
    let temp: TrieNode = this.root;
    for (let i = 0; i < word.length; i++) {
      if (!temp!.map.has(word.charAt(i))) return false;
      temp = temp!.map.get(word.charAt(i))!;
    }
    return temp!.isEndOfWord;
  }
  clear(): void {
    this.root = new TrieNode();
  }
}

const trie=new Trie();
trie.add("apply")
trie.add("app")
trie.add("apple")
trie.delete("apply")
console.log(trie.contains("apply"))
console.log(trie.contains("app"))
console.log(trie.contains("apple"))
