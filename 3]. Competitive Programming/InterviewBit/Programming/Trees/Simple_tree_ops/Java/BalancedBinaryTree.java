public class Solution {
    public int isBalanced(TreeNode root) {
             if(checkheight(root)==false)
             return 0;
            return 1;
    }
     public  boolean checkheight(TreeNode root){
        if(root==null){return true;}
        int lh=calcheight(root.left);
        int rh=calcheight(root.right);
        if(Math.abs(lh-rh)<=1&&checkheight(root.left)&&checkheight(root.right)){
            return true;
        }
       return false;
        
    }
    public  int calcheight(TreeNode root){
        if(root==null){return 0;}
        return (1+Math.max(calcheight(root.left),calcheight(root.right)));
    }
}
