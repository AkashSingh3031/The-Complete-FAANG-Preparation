#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[2];
};

TrieNode* root;
int ans;

void insertRowInTrie(string row) {
    TrieNode* cur = root;

    for(char ch: row) {
        int idx = ch - '0';

        if(cur->children[idx] == NULL) {
            cur->children[idx] = new TrieNode();
        }

        cur = cur->children[idx];
    }

    if(!cur->isEnd) {
        cur->isEnd = true;
        ans++;
    }
}

void printUniqueRows() {
    vector<string> res;

    queue<pair<TrieNode*, string>> q;
    q.push({root, ""});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(cur.first->isEnd) {
            res.push_back(cur.second);
        }

        if(cur.first->children[0] != NULL) {
            string next = cur.second + '0';
            q.push({cur.first->children[0], next});
        }

        if(cur.first->children[1] != NULL) {
            string next = cur.second + '1';
            q.push({cur.first->children[1], next});
        }
    }

    for(string row: res) {
        for(char ch: row) {
            cout<<ch<<' ';
        }
        cout<<endl;
    }
}

int main() {
    root = new TrieNode();
    ans = 0;

    int mat[4][5] = {{0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 1, 0, 0}};

    for(int i=0; i<4; ++i) {
        string word = "";
        for(int j=0; j<5; ++j) {
            if(mat[i][j] == 0)
                word+='0';
            else 
                word+='1';
        }

        insertRowInTrie(word);
    }

    cout<<"Unique rows are: "<<ans<<endl;
    printUniqueRows();

    return 0;
}