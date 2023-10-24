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
        
        queue<Node *> q;

        if(root != NULL)
            q.push(root);

        while(!q.empty()){
            int sz = q.size();
            Node * cur = q.front();
            if(cur->left != NULL)
                q.push(cur->left); 
            if(cur->right != NULL)
                q.push(cur->right);
            q.pop();
            sz--;
            while(sz > 0){
                Node * top = q.front();
                cur->next = top;
                q.pop();
                if(top->left != NULL)
                    q.push(top->left);
                if(top->right != NULL)
                    q.push(top->right);
                cur = top;
                sz--;
            }

            cur->next = NULL;
        }
        return root;
    }
};