class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        //starting with 1
        int ans = INT_MAX;
        int start = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(stoi(s.substr(i, 1)) != start)
                cnt++;
            start = (start + 1)%2;
        }

        ans = min(cnt, ans);
        cnt = 0;
        start = 0;
        for(int i = 0; i < n; i++){
            if(stoi(s.substr(i, 1)) != start)
                cnt++;
            start = (start + 1)%2;
        }
        ans = min(ans, cnt);
        return ans;
    }
};