public class Solution {
    List<Integer> al=new ArrayList<Integer>();
    public int kthsmallest(TreeNode root, int k) {
        inorder(root);
        return al.get(k-1);
    }
    public void inorder(TreeNode root){
        if(root==null){return ;}
        inorder(root.left);
        al.add(root.val);
        inorder(root.right);
    }
}
