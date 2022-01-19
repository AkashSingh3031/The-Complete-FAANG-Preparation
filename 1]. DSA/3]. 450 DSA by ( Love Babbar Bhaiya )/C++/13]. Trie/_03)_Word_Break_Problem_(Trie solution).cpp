/*
   GFG problem link:-  https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1/
*/

/*
    Input: 
        12 ilikesamsung
        i
        like
        same
        sung
        samsung
        mobile
        ice
        cream
        icecream
        man
        go
        mango

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
    Trie *cur = root;
    for(auto &ch : word){
        if(cur->child[ch-'a']==NULL) cur->child[ch-'a'] = new Trie();
        cur=cur->child[ch-'a'];
    }
    cur->isEnd = true;
}

bool search(Trie* root, string &word){
    Trie *cur = root;
    for(auto &ch : word){
        if(cur->child[ch-'a']==NULL) return false;
        cur=cur->child[ch-'a'];
    }
    return cur->isEnd ? true : false;
}

bool dfs(Trie* root, string &s, int idx){
    if(idx < 0) return true;
    string str="";
    for(int i=idx; i>=0; --i){
        str.push_back(s[i]);
        reverse(str.begin(),str.end());
        if(search(root,str)){ 
            if(dfs(root,s,i-1)) return true;
        }
        reverse(str.begin(),str.end());
    }
    return false;
}


int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<string> words(n);
    for(int i=0; i<n; ++i){
        cin>>words[i];
    }

    Trie *root = new Trie();
    for(int i=0; i<n; ++i){
        insert(root,words[i]);
    }

    dfs(root,s,s.size()-1) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}