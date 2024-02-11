class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();
        
        // priority_queue<int> pq;
        unordered_map<char, int> um;
        
        vector<int> vs;
        
        for(int i = 0; i < n; i++){
            for(char c : words[i]){
                um[c]++;
            }
            vs.push_back(words[i].size());
        }
        
        sort(vs.begin(), vs.end());
        int pairs = 0;
        for(auto & x : um){
            pairs += (x.second/2);
        }
        
        int ans = 0;
        for(int i =0; i < n; i++){
            if(vs[i]/2 <= pairs){
                pairs -= vs[i]/2;
                ans++;
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};