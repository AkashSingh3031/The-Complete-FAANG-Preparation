public class Solution {
    public TreeNode invertTree(TreeNode root) {
                if(root==null){return root;}
        invert(root);
        return root;
    }
    public void invert(TreeNode root){
        if(root.left==null&&root.right==null){
            return ;
        }
        TreeNode temp=root.right;
        root.right=root.left;
        root.left=temp;
        if(root.left!=null)
        invert(root.left);
        if(root.right!=null)
        invert(root.right);
    }
}