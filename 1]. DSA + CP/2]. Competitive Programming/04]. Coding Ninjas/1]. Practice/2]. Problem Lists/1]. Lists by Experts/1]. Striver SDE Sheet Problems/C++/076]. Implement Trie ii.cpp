struct Node{
    Node* link[26];
    int count = 0;
    int wordEnd = 0;
    bool isEnd = false;
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* curr = root;
        for(auto &it : word){
            if(!curr->link[it - 'a']){
                 curr->link[it - 'a'] = new Node();
            }
            curr = curr->link[it - 'a'];
            curr->count++;
        }
        curr->wordEnd++;
        curr->isEnd = true;
    }
    int countWordsEqualTo(string &word){
        Node* curr = root;
        for(auto &it : word){
            if(!curr->link[it - 'a']){
                 return 0;
            }
            curr = curr->link[it - 'a'];
        }
        if(!curr->isEnd) return 0;
        return curr->wordEnd;   
    }
    int countWordsStartingWith(string &word){
        Node* curr = root;
        for(auto &it : word){
            if(!curr->link[it - 'a']){
                 return 0;
            }
            curr = curr->link[it - 'a'];
        }
        return curr->count;    
    }
    void erase(string &word){
        Node* curr = root;
        for(auto &it : word){
            Node* temp = curr->link[it - 'a'];
            temp->count--;
            if(temp->count == 0) curr->link[it - 'a'] = NULL;
            curr = temp;
        }
        curr->wordEnd--;
        if(curr->wordEnd == 0) curr->isEnd = false;        
    }
};