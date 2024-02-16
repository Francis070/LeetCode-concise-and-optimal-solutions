struct Node {
    Node * next_node[26];
    bool is_end = false;

    Node(){
        for(int i = 0; i < 26; i++){
            next_node[i] = NULL;
        }
        is_end = false;
    }
};

class Trie{
public : 
    Node * source = new Node();
    Trie(){

    }

    void insert(string word){
        Node * temp = source;

        for(char c : word){
            if(temp->next_node[c - 'a'] == NULL){
                Node * nn = new Node();
                temp->next_node[c - 'a'] = nn;
                temp = nn;
            }
            else{
                temp = temp->next_node[c - 'a'];
            }
        }

        temp->is_end = true;
    }

    void get_strings(Node * temp, string cs, vector<string> & qw){
        if(temp == NULL || qw.size() >= 3)
            return;
            
        if(temp->is_end == true && qw.size() < 3){
            qw.push_back(cs);
            // return;
        }
        
        for(int i = 0; i < 26; i++){
            if(temp->next_node[i] != NULL && qw.size() < 3){
                get_strings(temp->next_node[i], cs + char('a' + i), qw);
            }
        }
        
    }

    vector<vector<string>> suggest(string word){
        vector<vector<string>> suggestions;
        string cur = "";

        Node * temp = source;
        bool test = true;
        for(int i = 0; i < word.size(); i++){
            cur += word[i];

            if(temp->next_node[word[i] - 'a'] != NULL && test){
                temp = temp->next_node[word[i] - 'a'];
                
                vector<string> qw;
                get_strings(temp,"", qw);

                for(int j = 0; j < qw.size(); j++){
                    qw[j] = cur + qw[j];
                }

                suggestions.push_back(qw);
            }
            else{
                test = false;
                suggestions.push_back({});
            }
        }

        return suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie * all_words = new Trie();

        for(string items : products)    
            all_words->insert(items);

        vector<vector<string>> res = all_words->suggest(searchWord);

        return res;
    }
};