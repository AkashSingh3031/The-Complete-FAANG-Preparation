#include<bits/stdc++.h>
typedef struct Node
{
    int height;
    int left;
    int right;
}
Node;
int heightOfTheTree(vector<int>& inorder, vector<int>& level, int N)
{
   queue<Node> q;
    Node it;
    
    it.height=0;
    it.left=0;
    it.right=N-1;
    
    q.push(it);
    int pos[N+1];
    for(int i=0;i<N;i++)
    {
        pos[inorder[i]]=i;
    }
    
    int mxheight=0;
    
    for(int i=0;i<N;i++)
    {
        int curr=level[i];
        
        Node now=q.front();
        q.pop();
        
        int currPos=pos[curr];
        
        //left child Present
        if(currPos>now.left)
        {
            Node newNode;
            
            newNode.height=now.height+1;
            mxheight=max(mxheight,newNode.height);
            newNode.left=now.left;
            newNode.right=currPos-1;
            
            q.push(newNode);
        }
        if(currPos<now.right)
        {
            Node newNode;
            
            newNode.height=now.height+1;
            mxheight=max(mxheight,newNode.height);
            newNode.left=currPos+1;
            newNode.right=now.right;
            
            q.push(newNode);
        }
    }
   return mxheight;
}