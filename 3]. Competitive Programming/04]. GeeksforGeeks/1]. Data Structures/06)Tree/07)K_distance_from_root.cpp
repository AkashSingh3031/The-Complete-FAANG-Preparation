vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  
  queue<Node*>q;
  q.push(root);
  int depth=0;
  vector<int>v;
  int i;
  if(k==0)
  {
      v.push_back(root->data);
      return v;
  }
  while(!q.empty())
  {
      
      int size=q.size();
      
      for(i=0;i<size;i++)
      {
          Node*temp=q.front();
          q.pop();
          if(temp->left)
          {
              q.push(temp->left);
          }
          if(temp->right)
          {
              q.push(temp->right);
          }
         
         
          
      }
      depth++;
      if(depth==k)
      {
          while(!q.empty())
          {
          v.push_back(q.front()->data);
          q.pop();
          }
          return v;
      }
  }
  return v;
  
