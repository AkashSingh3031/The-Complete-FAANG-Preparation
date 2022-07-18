struct TrieNode{
    TrieNode* child[26];
};

TrieNode* getNode(int index)
{
    TrieNode* node = new TrieNode();
    for(int i=0; i<26; i++)
        node->child[i]=NULL;
    return node;
}

int countDistinctSubstrings(string &word)
{
    //    Write your code here.
    TrieNode* root = getNode('/'-'a');
    int cnt = 0;
    for(int i=0; i<word.length(); i++)
    {
        TrieNode* curr = root;
        int index;
        for(int j=i; j<word.length(); j++)
        {
            index = word[j]-'a';
            if(curr->child[index] == NULL)
            {
                curr->child[index] = getNode(index);
                cnt++;                
            }
            curr = curr->child[index];
        }
    }
    return cnt+1;
}