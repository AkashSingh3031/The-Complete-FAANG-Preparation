// Check if two Strings are anagrams of each other
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// For example, "listen" is an anagram of "silent".

import java.util.*;
public class Anagram {
    public static void anagram(String str1, String str2) {
        int m = str1.length();
        HashMap<Character, Integer> mp = new HashMap<>();
        int j = 0;
        char c;
        if (str1.length() != str2.length()) {
            System.out.println("false");
            return;
        }
        for (int i = 0; i < str1.length(); i++) {
            c = str1.charAt(i);
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        for (int i = 0; i < str2.length(); i++) {
            if (!mp.containsKey(str2.charAt(i))) {
                System.out.println("false");
                return;
            } else {
                if (mp.get(str2.charAt(i)) == 0) {
                    System.out.println("false");
                    return;
                }
                mp.put(str2.charAt(i), mp.get(str2.charAt(i)) - 1);
            }
        }
        System.out.println("true");
    }

    
    public static void main(String args[]){
        anagram("abab","baa");
        anagram("aba","aab");
        anagram("listee", "silent");
    }
}
