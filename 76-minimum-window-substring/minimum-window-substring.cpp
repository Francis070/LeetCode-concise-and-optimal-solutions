class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        unordered_map<char, int> tot;
        int cnt = 0;
        unordered_map<char, int> rt;
        unordered_set<char> st;
        for(char c : t)
            st.insert(c);

        int i =0 , j = 0;

        for(char c : t){
            tot[c]++;
        }
        int ans = n + 5;
        string res = "";
        while(j < n){
            if(tot.find(s[j]) != tot.end()){
                rt[s[j]]++;
                if(rt[s[j]] == tot[s[j]])
                    cnt++;
            }

            if(cnt == st.size()){
                
                while(i < j){
                    if(tot.find(s[i]) == tot.end()){
                        i++;
                    }
                    else{
                        if(rt[s[i]] - 1 >= tot[s[i]]){
                            rt[s[i]]--;
                            i++;
                        }
                        else{
                            
                            break;
                        }
                    }
                }
                // cout<<i<<" "<<j<<endl;
                // cout<<i<<" "<<j<<" "<<s[j]<<" "<<tot[s[j]]<<" "<<rt[s[j]]<<endl;
                if(ans > (j - i + 1)){
                    res = s.substr(i, j - i + 1);
                }
                ans = min(ans, j - i + 1);
            }

            j++;
        }
        // cout<<ans;
        // cout<<res;
        if(ans == n + 5)
            return "";
        

        return res;
    }
};