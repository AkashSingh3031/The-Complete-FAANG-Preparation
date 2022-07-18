/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {
public:
    Trie* a[26];
    bool fl;
    Trie() {
        fl = false;
    }
    void insert(string s) {
        Trie*curr =   this;
        for(int i = 0; i < s.length();i++){
            if(!curr->a[s[i] - 'a']){
                curr->a[s[i] - 'a'] = new Trie;
            }
            curr = curr->a[s[i] - 'a'];
        }
        curr->fl = true;
    }
    bool search(string s) {
        Trie*curr = this;
        for(int i = 0; i < s.length(); i++){
            if(curr->a[s[i] - 'a'] == NULL){
                return false;
            }
            curr = curr->a[s[i] - 'a'];
        }
        if(curr->fl == true)return true;
        else return false;
    }
    bool startsWith(string s) {
        Trie*curr = this;
        for(int i = 0; i < s.length(); i++){
            if(curr->a[s[i] - 'a'] == NULL){
                return false;
            }
            curr = curr->a[s[i] - 'a'];
        }
        return true;
    }
};