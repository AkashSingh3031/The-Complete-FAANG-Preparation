#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    vector<int> indices;
};

TrieNode* root;

void insertWordInTrie(string word, int wordIdx) {
    TrieNode* cur = root;

    for(char ch: word) {
        int idx = ch - 'a';

        if(cur->children[idx] == NULL) {
            cur->children[idx] = new TrieNode();
        }

        cur = cur->children[idx];
    }

    cur->indices.push_back(wordIdx);
}

void printAnagrams(vector<string> words, vector<int> indices) {
    for(int idx: indices) {
        cout<<words[idx]<<' ';
    }
    cout<<endl;
}

int main() {
    root = new TrieNode();

    vector<string> words = {"cat", "dog", "tac", "god", "act"};
    for(int i=0; i<words.size(); ++i) {
        string cur = words[i];
        sort(cur.begin(), cur.end());
        insertWordInTrie(cur, i);
    }

    queue<TrieNode*> q;
    q.push(root);

    while(!q.empty()) {
        TrieNode* cur = q.front();
        q.pop();

        if(cur->indices.size() != 0) {
            printAnagrams(words, cur->indices);
        }

        for(int i=0; i<26; ++i) {
            if(cur->children[i] != NULL) {
                q.push(cur->children[i]);
            }
        }
    }

    return 0;
}