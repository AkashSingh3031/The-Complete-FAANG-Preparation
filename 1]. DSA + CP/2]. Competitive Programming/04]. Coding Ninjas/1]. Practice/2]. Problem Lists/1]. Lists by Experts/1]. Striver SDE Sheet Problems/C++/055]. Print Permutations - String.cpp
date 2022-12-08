void findpermutations(int index, string&s, vector<string>&ans)
{
    if(index==s.size())
    {
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        swap(s[index],s[i]);
        findpermutations(index+1,s,ans);
        swap(s[index],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    int index=0;
    findpermutations(index,s,ans);
    return ans;
}