struct Node{
    Node * next_node[26];
    bool is_end;

    Node() {
        for(int i =0; i < 26; i++)
            next_node[i] = NULL;
        is_end = false;
    }
};

class WordDictionary {
public:
    Node *source = new Node();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node * temp = source;
        for(char c : word){
            if(temp->next_node[c - 'a'] == NULL){
                Node * newnode = new Node();
                temp->next_node[c - 'a'] = newnode;
                temp = newnode;
            }
            else{
                temp = temp->next_node[c - 'a'];
            }
        }

        temp->is_end = true;
    }

    bool rec(Node * root, int ind, string word){
        if(root == NULL )
            return false;

        if(ind >= word.size()){
            return root->is_end;
        }

        bool ans = false;
        if(word[ind] != '.'){
            if(root->next_node[word[ind] - 'a'] != NULL){
                ans = ans || rec(root->next_node[word[ind] - 'a'], ind + 1, word);
            }
            else{
                ans = ans || false;
                return ans;
            }
        }
        else{
            for(int i =0 ; i < 26; i++){
                if(root->next_node[i] != NULL){
                    ans = ans || rec(root->next_node[i], ind + 1, word);
                }
            }
        }

        return ans;
    }
    
    bool search(string word) {
        bool ans = rec(source, 0, word);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */