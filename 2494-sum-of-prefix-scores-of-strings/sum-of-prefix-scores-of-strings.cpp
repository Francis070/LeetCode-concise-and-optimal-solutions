struct Node {
    // Node* links[26];
    // unordered_map<int, Node *> links;
    map<int, pair<Node * , int>> mp;
    bool flag = false;

    // int cnt[26] = {0};
    // unordered_map<int, int> cnt;

    bool containsKey(char ch) {
        if(mp.find(ch - 'a') != mp.end())
            return true;
        return false;
        // return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        mp[ch - 'a'] = {node, 0};
    }

    Node* get(char ch) {
        return mp[ch - 'a'].first;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node->mp[word[i] - 'a'].second++;
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    int search(string word) {
        Node* node = root;
        int sum = 0;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            sum += node->mp[word[i] - 'a'].second;
            node = node->get(word[i]);
        }

        return sum;
    }

    int startsWith(string prefix) {
        Node* node = root;
        int cnt = 0;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return cnt;
            }
            cnt++;
            node = node->get(prefix[i]);
        }
        
        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        int n = words.size();
        for(string s : words){
            trie.insert(s);
        }

        vector<int> ans(words.size());

        for(int i =0 ; i < n; i++){
            ans[i] = trie.search(words[i]);
        }

        return ans;
    }
};