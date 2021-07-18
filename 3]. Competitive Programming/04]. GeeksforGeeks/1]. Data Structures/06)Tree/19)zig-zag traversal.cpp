vector <int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node*>s1;
	stack<Node*>s2;
	s1.push(root);
	vector<int>v;
	while(!s1.empty()||!s2.empty())
	{
	    while(!s1.empty())
	    {
	        Node*temp1=s1.top();
	        v.push_back(temp1->data);
	        s1.pop();
	        if(temp1->left!=NULL)
	        {
	            s2.push(temp1->left);
	        }
	        if(temp1->right)
	        {
	            s2.push(temp1->right);
	        }
	        
	        
	    }
	    while(!s2.empty())
	    {
	        Node* temp2=s2.top();
	        v.push_back(temp2->data);
	        s2.pop();
	        if(temp2->right)
	        {
	            s1.push(temp2->right);
	        }
	        if(temp2->left)
	        {
	            s1.push(temp2->left);
	        }
	    }
	}
	return v;
	
}
