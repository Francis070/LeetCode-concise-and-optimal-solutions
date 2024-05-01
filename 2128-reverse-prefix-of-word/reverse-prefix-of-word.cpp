class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = word;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(word[i] == ch){
                string news = word.substr(0, i + 1);

                reverse(news.begin(), news.end());
                news += word.substr(i + 1, n - i - 1);
                ans = news;
                break;
            }
        }

        return ans;
    }
};