/*
Example
    s: “workattech”
    Result: 6
    Explanation: Longest vaild substring is “workat”.
    
    s: “mississippi”
    Result: 3
    Explanation: Longest vaild substrings are “mis” and “sip”, both of length 3.
    
Sample Input
  2
  10
  workattech
  11
  mississippi

Expected Output
  6
  3
*/

int longestSubstringWithoutRepeat(string s) {
    // add your logic here
	vector<int> dict(256, -1);
	int maxlen=0, start=0;
	
	for(int i=0; i<s.size(); i++) {
		if(dict[s[i]] != -1)
			start = max(start, dict[s[i]]+1);
		dict[s[i]] = i;
		maxlen = max(maxlen, i-start+1);
	}
	return maxlen;
}
