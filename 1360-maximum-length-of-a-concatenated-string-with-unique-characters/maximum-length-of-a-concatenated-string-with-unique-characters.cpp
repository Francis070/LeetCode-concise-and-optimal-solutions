class Solution {
public:
    bool check_dup(string &a, string &b){
        unordered_set<char> st;
        for(char c : a)
            st.insert(c);
        for(char c : b){
            if(st.find(c) != st.end())
                return false;
        }

        return true;
    }

    bool chk_char(string &a){
        unordered_set<char> st;
        for(char c : a){
            if(st.find(c) != st.end())
                return false;
            else
                st.insert(c);
        } 
        return true;
    }
    void rec(int ind, string cur, vector<string>& arr, vector<int> &chk, int &ans){
        if(ind >= arr.size()){
            ans = max(static_cast<int>(ans), static_cast<int>(cur.size()) );
            return;
        }

        // not take the current string 
        if(check_dup(cur, arr[ind]) && chk[ind] != -1){
            rec(ind + 1, cur + arr[ind], arr,chk, ans);
        }
        // take the current string
        rec(ind + 1, cur, arr,chk, ans);
    }

    int maxLength(vector<string>& arr) {
        int n =arr.size();
        vector<int> chk(n, 1);
        for(int i = 0; i < n; i++){
            if(!chk_char(arr[i]))
                chk[i] = -1;
        }

        int ans = 0;
        rec(0, "", arr, chk, ans);

        return ans;
    }
};