public class Solution {
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> alist=new ArrayList<ArrayList<Integer>>();
        
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        int y=0;
        while(q.size()>0)
        {
            ArrayList<Integer> a=new ArrayList<Integer>();
            int k=q.size();
            TreeNode x=null;
            for(int j=0;j<k;j++)
            {
                x=q.peek();
                q.remove();
               a.add(x.val);
                //System.out.print(x.data+" ");
                if(x.left!=null)
                q.add(x.left);
                if(x.right!=null)
                q.add(x.right);
            }
            if(y%2==0)
            alist.add(a);
            else{
                Collections.reverse(a);
                alist.add(a);
            }
            y++;
            //System.out.println();
        }
        return alist;
        
    }
}