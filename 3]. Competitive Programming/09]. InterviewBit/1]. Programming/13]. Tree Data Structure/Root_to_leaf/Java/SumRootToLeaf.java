public class Solution {
    public int sumNumbers(TreeNode A) {
        return (int)findsum(A,(long)0);
    }
    public long findsum(TreeNode root,Long sum){
        if(root==null){return (long)0;}
        else
        sum=Long.parseLong(Long.toString(sum)+Long.toString(root.val))%1003;
         // System.out.println(sum+" "+root.data);
        if (root.left == null && root.right == null) 
            return sum; 
        
        return findsum(root.left,sum)+findsum(root.right,sum);
    }
}