struct Node {
    Node* links[10];

    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - '0'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - '0'] = node;
    }

    Node* get(char ch) {
        return links[ch - '0'];
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
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int s : arr1)
            trie.insert(to_string(s));

        int ans = 0;
        for(int s : arr2)
            ans = max(ans, trie.startsWith(to_string(s)));

        return ans;
    }
};