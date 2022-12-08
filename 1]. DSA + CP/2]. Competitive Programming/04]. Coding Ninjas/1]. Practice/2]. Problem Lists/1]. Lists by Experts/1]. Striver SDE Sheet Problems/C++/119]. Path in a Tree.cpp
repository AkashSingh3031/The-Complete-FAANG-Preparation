/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


void traverse(TreeNode<int>* node, int x, vector<int>& order){
    if(!node) return;
    
    order.push_back(node->data);

    if(node->data == x) return;

    traverse(node->left, x, order);
    traverse(node->right, x, order);

    if(order[order.size()-1] != x)
        order.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> order;
    traverse(root, x, order);
    return order;
}