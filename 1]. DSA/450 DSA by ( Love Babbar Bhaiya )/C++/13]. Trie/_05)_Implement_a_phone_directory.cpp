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
        int idx = ch-'a';
        if(cur->children[idx] == NULL) {
            cur->children[idx] = new TrieNode();
        }

        cur = cur->children[idx];
    }

    cur->isEnd = true;
}

vector<string> searchResults(string pre) {
    vector<string> res;

    TrieNode* cur = root;
    for(char ch: pre) {
        int idx = ch - 'a';

        if(cur->children[idx] == NULL)
            return res;
        
        cur = cur->children[idx];
    }

    queue<pair<TrieNode*, string>> q;
    q.push({cur, pre});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(cur.first->isEnd) {
            res.push_back(cur.second);
        }

        for(int i=0; i<26; ++i) {
            if(cur.first->children[i] != NULL) {
                string next = cur.second + (char)(i+'a');
                q.push({cur.first->children[i], next});
            }
        }
    }

    return res;
}

int main() {

    root = new TrieNode();

    vector<string> words = {"rahul", "raman", "ram", "hari"};
    for(string word: words) {
        insertWordInTrie(word);
    }

    string query = "ramesh";
    string cur = "";
    for(char ch: query) {
        cur+=ch;
        vector<string> res = searchResults(cur);

        cout<<"Results based on \""<<cur<<"\" are: \n";
        if(res.size() == 0) {
            cout<<"NO RESULTS FOUND!\n\n";
            continue;
        }

        for(string word: res) {
            cout<<word<<endl;
        }
        cout<<endl<<endl;
    }

    return 0;
}