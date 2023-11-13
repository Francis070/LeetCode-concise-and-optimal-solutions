class Solution {
public:

    static bool comp(char a, char b){
        return int(a) < int(b);
    }

    string sortVowels(string s) {
        int n = s.size();

        vector<int> res(n, -1);
        string vowles = "";
        for(int i = 0; i < n; i++){
            char c = s[i];
            int ascii = int(c);
            if(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'i' || c == 'I' || c == 'O' || c == 'o' || c == 'U' || c == 'u'){
                vowles += c;
            }
            else
                res[i] = ascii;
        }
        string ans = "";
        
        sort(vowles.begin(), vowles.end(), comp);

        int j= 0;
        for(int i = 0; i < n; i++){
            if(res[i] == -1){
                res[i] = int(vowles[j]);
                j++;
            }
        }

        for(int i = 0; i < n; i++){
            ans += char(res[i]);
        }
        return ans;
    }
};