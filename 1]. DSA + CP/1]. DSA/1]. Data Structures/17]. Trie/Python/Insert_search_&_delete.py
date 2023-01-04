class TrieNode:
    def __init__(self):
        self.children = [None]*26

        self.isEndofWord = False

class Trie:
    def __init__(self):
        self.root = self.getNode()

    def getNode(self):
        return TrieNode()

    def charToIndex(self, ch):

        return ord(ch) - ord('a')

    def insert(self, key):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.charToIndex(key[level])

            if not pCrawl.children[index]:
                pCrawl.children[index] = self.getNode()
            pCrawl = pCrawl.children[index]
        
        pCrawl.isEndofWord = True

    def search(self, key):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.charToIndex(key[level])

            if not pCrawl.children[index]:
                return False
            pCrawl = pCrawl.children[index]
        
        return pCrawl.isEndofWord

    def delete(self, key):
        pCrawl = self.root
        if self.search(key):
            for level in range(len(key)):
                index = self.charToIndex(key[level])
                pCrawl = pCrawl.children[index]
         
        pCrawl.isEndofWord = False

# driver function
def main():
 
    keys = ["the", "a", "there", "anaswe", "any", "by", "their"]
    output = ["Not present in trie", "Present in trie"]
 
    t = Trie()
 
    for key in keys:
        t.insert(key)
 
    print("{} ---- {}".format("the",output[t.search("the")]))
    print("{} ---- {}".format("these",output[t.search("these")]))
    print("{} ---- {}".format("their",output[t.search("their")]))
    print("{} ---- {}".format("thaw",output[t.search("thaw")]))
    print("{} ---- {}".format("anaswe",output[t.search("anaswe")]))

    t.delete('anaswe')

    print("{} ---- {}".format("anaswe",output[t.search("anaswe")]))
 
if __name__ == '__main__':
    main()