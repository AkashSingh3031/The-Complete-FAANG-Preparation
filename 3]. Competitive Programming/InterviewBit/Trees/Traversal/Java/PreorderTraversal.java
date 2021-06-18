public class Solution {
    public ArrayList<Integer> preorderTraversal(TreeNode A) {
 		ArrayList<Integer> ans = new ArrayList<>();
    	Stack<TreeNode> stack = new Stack<>();

    	if (A == null) {
    		return ans;
    	}
    	stack.push(A);

    	while (!stack.isEmpty()) {
    		TreeNode temp = stack.pop();
    		ans.add(temp.val);

    		if (temp.right != null) {
    			stack.push(temp.right);
    		}
    		if (temp.left != null) {
    			stack.push(temp.left);
    		}
    	}

    	return ans;
    }
}
