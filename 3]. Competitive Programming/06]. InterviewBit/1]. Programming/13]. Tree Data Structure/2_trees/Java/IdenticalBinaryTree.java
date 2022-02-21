class Solution {
    public int isSameTree(TreeNode p, TreeNode q) {
        if(issame(p,q)==false)
        return 0;
        else
        return 1;
        
    }
    public boolean issame(TreeNode root1,TreeNode root2){
        if(root1==null && root2!=null)
            return false;
        if(root1!=null&&root2==null)
            return false;
        if(root1==null&&root2==null)
            return true;
        if(root1.val!=root2.val)
            return false;
        else{
            return issame(root1.left,root2.left)&&issame(root1.right,root2.right);
        }
    }
    
    
}