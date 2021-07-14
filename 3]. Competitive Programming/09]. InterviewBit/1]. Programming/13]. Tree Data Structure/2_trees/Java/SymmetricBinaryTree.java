public class Solution {
    public int isSymmetric(TreeNode root) {
 if(root==null){return 1;}
 if(check(root.left,root.right)==true)
 return 1;
 else
 return 0;
 
}
public boolean check(TreeNode Lst,TreeNode Rst){
    if(Lst==null&&Rst==null)
        return true;
    else if(Lst==null||Rst==null)
        return false;
    if(Rst.val!=Lst.val)
        return false;
    return check(Lst.left,Rst.right)&&check(Lst.right,Rst.left);
}
}
