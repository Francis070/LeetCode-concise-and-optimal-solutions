struct Node {
    Node * next_node[26];
    bool is_end;

    Node(){
        for(int i = 0; i < 26; i++)
            next_node[i] = NULL;
        is_end = false;
    }
};

class Trie{
public:

    Node * source = new Node();

    Trie(){

    }

    void insert(string root){
        Node * temp = source;

        for(char c : root){
            
            if(temp->next_node[c - 'a'] == NULL){
                Node * new_node = new Node();
                temp->next_node[c - 'a'] = new_node;
                temp = new_node;
            }
            else{
                temp = temp->next_node[c - 'a'];
            }
        }
        // cout<<endl;

        temp->is_end = true;
    }

    string search(string word){
        string res = "";
        Node * temp = source;
        for(int i = 0; i < word.size(); i++){
            if(temp->next_node[word[i] - 'a'] == NULL){
                if(temp->is_end == true)
                    return res;
                else
                    return "";
            }
            else{
                
                if(temp->is_end){
                    return res;
                }
                else{
                    res += word[i];
                    temp = temp->next_node[word[i] -'a'];
                }
            }
        }
        return res;
    }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sen) {
        Trie *all_words = new Trie();

        for(string word : dictionary){
            all_words->insert(word);
        }
        string res = "";
        string cur = "";
        for(int i = 0; i < sen.size(); i++){
            if(sen[i] == ' ') {
                string get_w = all_words->search(cur);
                // cout<<get_w<<endl;
                if(get_w == ""){
                    res += cur;
                }
                else{
                    res += get_w;
                }
                res += ' '; 
                cur = "";
            }
            else{
                cur += sen[i];
            }
        }

        string get_w = all_words->search(cur);
        if(get_w == ""){
            res += cur;
        }
        else{
            res += get_w;
        }

        return res;
    }
};