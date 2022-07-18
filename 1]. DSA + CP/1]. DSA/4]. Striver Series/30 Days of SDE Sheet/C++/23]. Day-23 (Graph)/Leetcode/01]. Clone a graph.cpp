/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
    unordered_map <Node*, Node*> clone;
public:
    Node* cloneGraph(Node* node) {
        if (!node) 
            return NULL;
        if (clone.count(node))
            return clone[node];
        Node* foo = new Node(node->val);
        clone[node] = foo;
        for (auto n : node->neighbors) {
            foo->neighbors.push_back(cloneGraph(n)); 
        }
        return foo;
    }
};