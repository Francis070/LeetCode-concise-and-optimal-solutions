class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        // unordered_map<char, int> um;
        int char_arr[26] = {0};

        for(int i =0; i < n; i++){   // collecting all the characters.
            for(char c : words[i]){
                char_arr[c - 'a']++;
            }
        }
        
// checking that whether the characters that were collected can be divided into the size of the words vector.
        for(int i = 0; i< 26; i++){
            if(char_arr[i] > 0 && char_arr[i] % n != 0)
                return false;
        }

        return true;
    }
};