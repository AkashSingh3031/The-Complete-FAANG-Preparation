#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
};

TrieNode* root;

void insertWord(string word) {
    TrieNode* cur = root;
    
    for(char ch: word) {
        int idx = ch-'a';
        if(cur->children[idx] == NULL) {
            cur->children[idx] = new TrieNode();
        }

        cur = cur->children[idx];
    }

    cur->isEnd = true;
}

bool searchWord(string word) {
    TrieNode* cur = root;

    for(char ch: word) {
        int idx = ch - 'a';
        if(cur->children[idx] == NULL) {
            return false;
        }

        cur = cur->children[idx];
    }

    return cur->isEnd;
}

int main() {

    root = new TrieNode();

    vector<string>words = {"hello", "hell", "helloworld"};
    for(string word: words) {
        insertWord(word);
    }

    cout<<searchWord("hell")<<endl;
    cout<<searchWord("helloo")<<endl;

    return 0;
}