/*
Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
    Input: digits = ""
    Output: []

Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations {};
        if (digits.size() == 0) {
            return combinations;
        }
        
        stack<string> nodes {};
        nodes.push({""});
        while (nodes.size()) {
            auto node = nodes.top();
            nodes.pop();
            
            if (node.size() == digits.size() ) {
                combinations.push_back(node);
                continue;
            }
            char c = digits[node.size()];
            //cout << c<< endl;
            
            switch (c) {
                case '2':
                    nodes.push({node + 'a'});
                    nodes.push({node + 'b'});
                    nodes.push({node + 'c'});
                    break;
                case '3':
                    nodes.push({node + 'd'});
                    nodes.push({node + 'e'});
                    nodes.push({node + 'f'});
                    break;
                case '4':
                    nodes.push({node + 'g'});
                    nodes.push({node + 'h'});
                    nodes.push({node + 'i'});
                    break;
                case '5':
                    nodes.push({node + 'j'});
                    nodes.push({node + 'k'});
                    nodes.push({node + 'l'});
                    break;
                case '6':
                    nodes.push({node + 'm'});
                    nodes.push({node + 'n'});
                    nodes.push({node + 'o'});
                    break;
                case '7':
                    nodes.push({node + 'p'});
                    nodes.push({node + 'q'});
                    nodes.push({node + 'r'});
                    nodes.push({node + 's'});
                    break;
                case '8':
                    nodes.push({node + 't'});
                    nodes.push({node + 'u'});
                    nodes.push({node + 'v'});
                    break;
                case '9':
                default:
                    nodes.push({node + 'w'});
                    nodes.push({node + 'x'});
                    nodes.push({node + 'y'});
                    nodes.push({node + 'z'});
                    break;
            }
        }
        
        return combinations;
    }
};