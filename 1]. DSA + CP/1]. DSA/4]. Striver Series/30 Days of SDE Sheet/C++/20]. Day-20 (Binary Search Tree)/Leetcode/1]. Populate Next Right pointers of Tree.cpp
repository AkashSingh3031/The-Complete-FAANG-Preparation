/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(size(q)) {
            Node* rightNode = nullptr; 
            for(int i = size(q); i; i--) {     
                auto cur = q.front(); q.pop(); 
                cur -> next = rightNode;  
                rightNode = cur; 
                if(cur -> right)            
                    q.push(cur -> right),    
                    q.push(cur -> left); 
            }
        }
        return root;
    }
};