/*
   GFG problem link:-  https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1/
*/

/*
    Input: 
        4 apple
        banana
        cocunut
        apple
        kiwi

    Output:
        True
*/

#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct Trie{
    Trie* child[ALPHABET_SIZE];
    bool isEnd = false;
};

void insert(Trie* root, string &word){
    Trie* cur = root;
    for(auto &ch : word){
        int idx = ch - 'a';
        if(cur->child[idx]==NULL) cur->child[idx] = new Trie();
        cur = cur->child[idx];
    }
    cur->isEnd = true;
}

bool search(Trie* root, string &key){
    Trie* cur = root;
    for(auto &ch : key){
        int idx = ch - 'a';
        if(cur->child[idx]==NULL) return false;
        cur = cur->child[idx];
    }
    return cur->isEnd ? true : false;
}


int main(){
    int n;
    cin>>n;

    string key;
    cin>>key;

    vector<string> words(n);
    for(int i=0; i<n; ++i){
        cin>>words[i];
    }

    Trie *root = new Trie();
    for(int i=0; i<n; ++i){
        insert(root,words[i]);
    }

    search(root,key) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}