# define ll long long

class Solution {
public:
    
    ll get_sq(vector<int> t1, vector<int> t2){
        if(t1[0] >= t2[2] || t2[0] >= t1[2] || t1[1] >= t2[3] || t2[1] >= t1[3])
            return 0;
        
        ll l = min(t1[2], t2[2]) - max(t1[0], t2[0]);
        ll b = min(t1[3], t2[3]) - max(t1[1], t2[1]);
        ll mn = min(l, b);
        return (mn * mn);
    }
    
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // vector<int> t1(4), t2(4);
                int t10 = bl[i][0]; int t11 = bl[i][1]; int t12 = tr[i][0]; int t13 = tr[i][1];
                int t20 = bl[j][0]; int t21 = bl[j][1]; int t22 = tr[j][0]; int t23 = tr[j][1];

                if(t10 >= t22 || t20 >= t12 || t11 >= t23 || t21 >= t13)
                    continue;
                
                ll l = min(t12, t22) - max(t10, t20);
                ll b = min(t13, t23) - max(t11, t21);
                ll mn = min(l, b);
                ans = max(ans,  (mn * mn));  
                
                // ll lar_sq = get_sq(t1, t2);
                // ans = max(ans, lar_sq);
            }
        }
        
        return ans;
    }
};