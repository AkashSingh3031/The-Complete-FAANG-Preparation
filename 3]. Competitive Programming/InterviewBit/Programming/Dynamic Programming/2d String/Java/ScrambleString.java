class Solution {
    HashMap<String,Boolean>map=new HashMap<String,Boolean>();
    public int isScramble(String s1, String s2) {
        if(helper(s1,s2)==true)
        return 1;
        else
        return 0;
    }
    public boolean helper(String a,String b){
        if(a.equals(b))
            return true;
        if(a.length()<=1)
            return false;
        StringBuilder sb=new StringBuilder(a);
        sb.append(" ");
        sb.append(b);
        String s=sb.toString();
        int n=a.length();
        if(map.containsKey(s)){
            return map.get(s);
        }
        boolean flag=false;
        boolean flag1=false;
        boolean flag2=false;
        for(int i=1;i<n;i++){
            
            if (helper(a.substring(0, i), b.substring(0, i)) 
            && helper(a.substring(i), 
                          b.substring(i))) { 
            flag1=true; 
        }
            if (helper(a.substring(0, i), 
                       b.substring(b.length()-i)) 
            && helper(a.substring(i), 
                          b.substring(0, b.length()- i))) { 
            flag2= true; 
        }
            if(flag1||flag2)
                flag=true;
            
            
        }
        map.put(s,flag);
        return flag;
        
        
        
        
        
    }
}