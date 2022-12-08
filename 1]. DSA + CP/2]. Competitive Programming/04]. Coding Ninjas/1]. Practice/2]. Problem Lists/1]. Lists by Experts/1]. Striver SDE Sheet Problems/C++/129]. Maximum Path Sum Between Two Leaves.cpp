/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void leaves(TreeNode<int> *root, int &count)
{
    if(root==NULL)
        return;
    leaves(root->left, count);
    leaves(root->right, count);
    if(root->left==NULL && root->right==NULL)
        count++;
}

long long solution(TreeNode<int> *root, long long &result)
{
    if(root==NULL)
       return 0;
   long long left=solution(root->left, result);
   long long right=solution(root->right, result);
   long long temp=root->val;
   long long ans= max(temp+left, max(temp+right, left+right+temp));
   result=max(result, ans);
   return max(temp+left, temp+right);
}

 

long long int findMaxSumPath(TreeNode<int> *root)
{
   // Write your code here.
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return -1;
    int count=0;
    leaves(root, count);
    if(count==1)
        return -1;
    long long result=-1;
        solution(root, result);
    return result;
}