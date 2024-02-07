/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

bool chk_parent(Node * a, Node * b){
    if(a == NULL){
        return false;
    }
    if(a->val == b->val)
        return true;
    bool chk = chk_parent(a->parent, b);
    
    return chk;
}

void get_path(Node * a, vector<Node*> & path){
    if(a == NULL)
        return;
    
    path.push_back(a);
    get_path(a->parent, path);
}

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(chk_parent(p, q))
            return q;
        else if(chk_parent(q, p))
            return p;

        vector<Node * > patha, pathb;

        get_path(p, patha);
        get_path(q, pathb);

        set<Node * > st;
        for(auto x : patha){
            st.insert(x);
        }
        for(auto x : pathb){
            if(st.find(x) != st.end())
                return x;
        }
        Node * t;
        return t;
    }
};