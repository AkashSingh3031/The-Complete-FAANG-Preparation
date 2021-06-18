#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
};

TrieNode* root;

void insertWordInTrie(string word) {
    TrieNode* cur = root;

    for(char ch: word) {
        int idx = ch - 'a';

        if(cur->children[idx] == NULL) {
            cur->children[idx] = new TrieNode();
        }

        cur = cur->children[idx];
    }

    cur->isEnd = 1;
}

bool findWordInTrie(string word) {
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

bool exist;

void checkExistence(string target) {
    if(target.size() == 0 || exist) {
        exist = true;
        return;
    }

    string cur = "";
    string rem = target;

    for(char ch: target) {
        cur+=ch;
        rem.erase(rem.begin());

        if(findWordInTrie(cur)) {
            checkExistence(rem);
        }
    }
}

int main() {

    root = new TrieNode();

    vector<string> words = {"i", "ice", "cream"};
    for(string word: words) {
        insertWordInTrie(word);
    }

    string target = "icecream";
    exist = false;
    checkExistence(target);

    if(exist) {
        cout<<target<<" can be created\n";
    } else {
        cout<<target<<" cannot be created\n";
    }

    return 0;
}