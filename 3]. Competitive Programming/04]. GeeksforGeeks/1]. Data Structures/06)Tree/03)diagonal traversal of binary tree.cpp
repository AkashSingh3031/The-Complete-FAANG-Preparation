vector<int> diagonal(Node *root)
{
   // your code here
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   vector<int>v;
   Node* p=root;
   while(!q.empty())
   {
       p=q.front();
       q.pop();
       if(p==NULL)
       {
          
          q.push(NULL);
       
       p=q.front();
       q.pop();
       if(p==NULL)
       {
           break;
       }
       }
       while(p!=NULL)
       {
           v.push_back(p->data);
           if(p->left)
           {
               q.push(p->left);
               
           }
          
           p=p->right;
       }
       
   }
   return v;
   
   
   
}
