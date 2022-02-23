/*
Example 1:
  Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
  Output: 20
Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.

Example 2:
  Input: input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
  Output: 32
Explanation: We have two files:
    "dir/subdir1/file1.ext" of length 21
    "dir/subdir2/subsubdir2/file2.ext" of length 32.
We return 32 since it is the longest absolute path to a file.
  
Example 3:
  Input: input = "a"
  Output: 0
Explanation: We do not have any files, just a single directory named "a".
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        string token;
        size_t max_len = 0;
        unordered_map<int, int> path_len;
        path_len[0] = 0;

        while (getline(ss, token)) {
            auto pos = token.find_last_of("\t");
            string name = (pos != std::string::npos) ? token.substr(pos + 1) : token;
            
            int depth = token.size() - name.size();
            if (token.find(".") != std::string::npos)
                max_len = max(max_len, path_len[depth] + name.size()); 
            else 
                path_len[depth + 1] = path_len[depth] + name.size() + 1;
        }
        return max_len;
    }
};
