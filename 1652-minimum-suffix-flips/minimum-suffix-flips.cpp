class Solution {
public:
    int minFlips(string target) {
        reverse(target.begin(), target.end());
        int n = target.size();
        int cnt_z = 0, cnt_o = 0, ans = 0;
        if(target[0] == '1')
            ans++;

        for(int i = 0; i < n; i++){
            if(target[i] == '1')
                cnt_o++;
            else
                cnt_z++;

            if(i > 0 && target[i] != target[i-1]){
                if(target[i] == '1'){
                    ans+=2;
                }
                // else{
                //     ans += 2
                // }
            }
        }

        return ans;
    }
};