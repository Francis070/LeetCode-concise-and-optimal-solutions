class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        // unordered_map<char, int> um;
        int arr[26] = {0};
        for(char c : s){
            arr[c - 'a']++;
        }

        for(int i = 0; i < n; i++){
            if(arr[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};