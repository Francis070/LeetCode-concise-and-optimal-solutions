class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> st;
        unordered_map<int, int> um;

        for(int i =0; i< n; i++){ um[arr[i]]++;}

        for(auto &x : um){
            if(st.find(x.second)!= st.end()) return false;
            else st.insert(x.second);
        }

        return true;
    } 
};