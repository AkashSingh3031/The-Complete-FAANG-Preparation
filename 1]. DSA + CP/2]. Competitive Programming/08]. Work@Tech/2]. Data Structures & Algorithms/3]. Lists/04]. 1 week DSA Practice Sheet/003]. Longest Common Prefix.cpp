/*
Example
    A: [“abc”, “abef”, “abccc”, “abftg”]
Longest common prefix: “ab”

Sample Input
  4
  4
  apple apply apollo abracadabra
  2
  qwerty hello
  3
  helloworld hell hello
  1
  hello
Expected Output
  a

  hell
  hello
*/

string longestCommonPrefix(vector<string> &str) {
    // add your logic here
	int n = str.size();
	if(n==0)
		return "";
	
	string res = "";
	sort(begin(str), end(str));
	string a = str[0], b = str[n-1];
	
	for(int i=0; i<a.size(); i++) {
		if(a[i] == b[i])
			res += a[i];
		else
			break;
	}
	return res;
}
