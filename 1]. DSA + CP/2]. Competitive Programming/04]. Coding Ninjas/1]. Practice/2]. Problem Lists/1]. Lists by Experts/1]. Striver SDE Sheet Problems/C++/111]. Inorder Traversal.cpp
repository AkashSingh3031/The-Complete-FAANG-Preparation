/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> vector;
    if(!root)
        return vector;
    stack<TreeNode *> stack;
    stack.push(root);
    while(!stack.empty())
    {
        TreeNode *pNode = stack.top();
        if(pNode->left)
        {
            stack.push(pNode->left);
            pNode->left = NULL;
        }
        else
        {
            vector.push_back(pNode->data);
            stack.pop();
            if(pNode->right)
                stack.push(pNode->right);
        }
    }
    return vector;
}