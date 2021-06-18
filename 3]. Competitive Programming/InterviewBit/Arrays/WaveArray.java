import java.util.*;
public class Solution {
    public int[] wave(int[] a) {
        
        Arrays.sort(a);
        for(int i=0;i<a.length-1;i=i+2){
            int temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
        return a;
    }
}
