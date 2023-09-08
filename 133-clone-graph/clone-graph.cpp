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
public:

    unordered_map<Node*, Node *> um;

    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;

        queue<Node * > q;
        q.push(node);

        Node * nn = new Node(node->val, {});
        um[node] = nn;

        while(!q.empty()){
            Node * cur = q.front();
            q.pop();

            for(auto x : cur->neighbors){
                if(um.find(x) == um.end()){
                    Node * qw = new Node(x->val, {});
                    um[x] = qw;
                    q.push(x);
                }

                um[cur]->neighbors.push_back(um[x]);
            }
        }

        return um[node];
    }
};