public class Solution {
    public ArrayList<Integer> postorderTraversal(TreeNode A) {
         ArrayList<Integer> ans= new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
       
        if (A == null) return ans;
        .
        while (A != null || !stack.isEmpty()) {
            if (A != null) {
                stack.push(A);
                A = A.left;
            }
            else {
                TreeNode temp = stack.peek().right;
                if (temp == null) {
                    temp = stack.pop();
                    ans.add(temp.val);
                    while(!stack.isEmpty() && temp == stack.peek().right) {
                        temp = stack.pop();
                        ans.add(temp.val);
                    }
                }
                else {
                    A = temp;
                }
        }
        
        
    }
    return ans;
}
}