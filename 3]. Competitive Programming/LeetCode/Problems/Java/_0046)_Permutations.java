class Solution {
    public List<List<Integer>> permute(int[] nums) {
        return permutationsHelper(nums, 0);
    }
    
   private List<List<Integer>> permutationsHelper(int[] input, int index) {
        if (index == input.length){
            List<List<Integer>> list = new ArrayList<>();
            list.add(new ArrayList<Integer>());
            return list;
        }

        List<List<Integer>> result = permutationsHelper(input, index + 1);
        int val = input[index];

        for (int i = result.size() - 1; i >= 0; i--) {
            if (!result.isEmpty()) {
                List<Integer> child = result.remove(i);
                for (int j = 0; j <= child.size(); j++) {
                    List<Integer> temp = new ArrayList<>();
                    temp.addAll(child);
                    temp.add(j, val);
                    result.add(temp);
                }
            }
        }
        return result;
    }
}
