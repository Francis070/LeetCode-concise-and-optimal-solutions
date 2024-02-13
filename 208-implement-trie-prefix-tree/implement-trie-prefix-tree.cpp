struct Node{
    // vector<Node*> next_node(26);
    Node * next_node[26];
    bool is_end;

    Node(){
        for(int i = 0; i < 26; i++)
            next_node[i] = NULL;
        is_end = false;
    }
};
class Trie {
public:
    Node * source = new Node();
    Trie() {
        
    }

    void insert(string word) {
        Node * temp = source;

        for(char c : word){
            if(temp->next_node[c - 'a'] == NULL){
                Node * next = new Node();
                temp->next_node[c - 'a'] = next;
                temp = next;
            }
            else{
                temp = temp->next_node[c - 'a'] ;
            }
        }

        temp->is_end = true;
    }
    
    bool search(string word) {
        Node * temp = source;

        for(int i = 0; i < word.size(); i++){
            if(temp->next_node[word[i] - 'a'] != NULL){
                temp = temp->next_node[word[i] - 'a'];
            }
            else
                return false;
        }

        return temp->is_end; 
    }
    
    bool startsWith(string prefix) {
        Node * temp = source;

        for(int i = 0; i < prefix.size(); i++){
            if(temp->next_node[prefix[i] - 'a'] != NULL){
                temp = temp->next_node[prefix[i] - 'a'];
            }
            else
                return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */