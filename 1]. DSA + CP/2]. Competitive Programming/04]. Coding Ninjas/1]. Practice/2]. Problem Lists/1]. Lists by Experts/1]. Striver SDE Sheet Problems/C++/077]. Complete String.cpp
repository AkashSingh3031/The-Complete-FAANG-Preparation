struct node{
    node *next[26]={NULL};
    bool isLeaf=false;
};
class trie{
    node *root;
    public:
    trie(){
        root=new node;
    }
    void insert(string &a){
        node *head=root;
        for(int i=0;i<a.size();i++){
            if(!head->next[a[i]-'a'])
                head->next[a[i]-'a']= new node;
            head=head->next[a[i]-'a'];
        }
        head->isLeaf=true;
    }
    bool search(string &s){
        node *head=root;
        for(int i=0;i<s.size();i++){
            if(!head->next[s[i]-'a'] or !head->next[s[i]-'a']->isLeaf) return false;
            head=head->next[s[i]-'a'];
        }
        return head->isLeaf;
    }
};
string completeString(int n, vector<string> &a){
    trie *t=new trie();
    for(auto i:a) t->insert(i);
    string ans="";
    for(auto i:a){
        if(!t->search(i)) continue;
        if(ans.size()==i.size()) ans=min(ans,i);
        else if(i.size()>ans.size()) ans=i;
    }
    if(ans=="") return "None";
    return ans;
}