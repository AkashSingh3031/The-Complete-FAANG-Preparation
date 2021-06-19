public class Solution {
    public int findheight(TreeNode root){
        if(root==null){return 0;}
        return 1+Math.max(findheight(root.left),findheight(root.right));
    }
    public int maxDepth(TreeNode A) {
        int t=findheight(A);
        return t;
    }
}