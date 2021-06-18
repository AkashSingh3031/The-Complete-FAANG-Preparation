public class Solution {
    HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
    public ArrayList<ArrayList<Integer>> verticalOrderTraversal(TreeNode A) {
    ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    
        int h =height(A);
        for (int i = 0; i <= h ;i++) {
            fillList(A, 0, i);
    
        }
        Object[] keys = map.keySet().toArray();
        Arrays.sort(keys);
        for (Object value : keys) {
            list.add(map.get(value));
        }
        return list;
    }
    
      int height(TreeNode root) { 
        if (root == null) 
           return 0; 
        else
        { 
            int lheight = height(root.left); 
            int rheight = height(root.right); 
              
            if (lheight > rheight) 
                return(lheight+1); 
            else return(rheight+1);  
        } 
    }
    
    public void fillList(TreeNode currNode, int Hlevel, int Vlevel) {
        if (currNode == null)  
            return;  
        if (Vlevel == 1)  
            insert(currNode.val, Hlevel);
        else if (Vlevel > 1)  {  
            fillList(currNode.left, Hlevel-1, Vlevel-1);  
            fillList(currNode.right,Hlevel+1, Vlevel-1);  
        }  
        
       
        
    }
    
    public void insert(int val, int level) {
        ArrayList<Integer> temp;
        if (map.containsKey(level)) {
            temp = map.get(level);
        } else {
            temp = new ArrayList<Integer>();
        }
        temp.add(val);
        map.put(level, temp);
    }
    }