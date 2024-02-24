struct Node{
    vector<Node*> next;
    bool is_end;
    int hotness;

    Node(){
        next.resize(27, NULL);
        is_end = false;
        hotness = 0;
    }
};

class Trie{
public:
    Node * source = new Node();

    // create the trie
    void add(string st, int hot, int chk){
        int n = st.size();
        Node * temp = source;
        for(char c : st){
            int pos = -1;
            if(c == ' ')
                pos = 0;
            else
                pos = c - 'a' + 1;

            if(temp->next[pos] == NULL){
                Node * nn = new Node();
                temp->next[pos] = nn;
            }
            temp = temp->next[pos];
            
        }   
        temp->is_end = true;
        if(chk == 1)
            temp->hotness += 1;
        else
            temp->hotness = hot;
    }

    pair<int, string> compare(pair<int, string> a, pair<int, string> b){
        // cout<<"--------"<<endl;
        // cout<<a.second<<" "<<b.second<<endl;
        if(a.first == b.first){
            if(a.second < b.second)
                return a;
            return b;
        }
        else{
            if(a.first > b.first)
                return a;
            return b;
        }
    }

    void get_suggestions(Node * root, string cur, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> &pq){
        if(root->is_end){
            pair<int, string> abhi;
            abhi.first = root->hotness;
            abhi.second = cur;

            // if(pq.size() >= 3){
            //     pair<int, string> tp = pq.top();
            //     cout<<tp.second<<endl;
            //     pq.pop();
            //     pair<int, string> mx = compare(abhi, tp);
            //     pq.push(mx);
            // }
            // else
                pq.push(abhi);
        }

        for(int i = 0;i < 27; i++){
            if(root->next[i] != NULL){
                if(i == 0){
                    get_suggestions(root->next[i], cur + ' ', pq);
                }
                else{
                    get_suggestions(root->next[i], cur + char('a' + i - 1), pq);
                }
            }
        }
    }

    static bool comp(pair<int, string> & a, pair<int, string> & b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        else{   
            return a.first > b.first;
        }
    }

    vector<string> suggest(string par){
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        Node * temp = source;
        for(char c : par){
            int pos= -1;
            if(c == ' ')
                pos = 0;
            else
                pos = c - 'a' + 1;
            
            if(temp->next[pos] == NULL){
                return {};
            }
            else
                temp = temp->next[pos];
        }
        vector<string> res;
        get_suggestions(temp, "", pq);

        vector<pair<int, string>> vqp;
        while(!pq.empty()){
            pair<int, string> cur = pq.top();
            pq.pop();
            vqp.push_back(cur);
        }
        sort(begin(vqp), end(vqp), comp);
        for(int i = 0; i < min(int(vqp.size()), 3); i++){
            string cur = par + vqp[i].second;
            res.push_back(cur);
        }
        return res;
    }
};

class AutocompleteSystem {
public:
    Trie aw;
    string par = "";
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        int n = sentences.size();
        for(int i = 0; i < n; i++){
            aw.add(sentences[i], times[i], 0);
        }
    }
    
    vector<string> input(char c) {
        vector<string > res;
        if(c != '#'){
            par += c;
            res = aw.suggest(par);
        }
        else{
            res = {};
            // return {};
            aw.add(par, 0, 1);
            par = "";
        }

        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */