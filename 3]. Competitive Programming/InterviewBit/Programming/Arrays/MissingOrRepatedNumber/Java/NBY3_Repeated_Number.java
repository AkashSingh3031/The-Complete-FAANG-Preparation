public class Solution {
    // DO NOT MODIFY THE LIST
    public int repeatedNumber(final List<Integer> a) {
        int res=-1;
        HashMap<Integer,Integer> h=new HashMap<Integer,Integer>();
        for(int i=0;i<a.size();i++){
            Integer c=h.get(a.get(i));
            if(h.get(a.get(i))==null)
            {
                 h.put(a.get(i),1);
            }
            else
            {
                h.put(a.get(i),++c);
            }
        }
        // System.out.println(map);
        Set se=h.keySet();
        for(Object i:se){
            if(h.get(i)>(a.size()/3)){
                res=(int)i;
                break;
            }
        }
        return res;
    }
}