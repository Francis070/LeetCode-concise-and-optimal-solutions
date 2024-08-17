#define ll long long
class Solution {
public:

    void getL(vector<ll> & prev, vector<ll> & lefm){
        lefm.resize(prev.size(), 0);

        lefm[0] = prev[0];
        for(int i = 1; i < prev.size(); i++){
            lefm[i] = max(lefm[i-1] - 1, prev[i]);
        }
    }

    void getR(vector<ll> & prev, vector<ll> & rigm){
        rigm.resize(prev.size(), 0);

        rigm.back() = prev.back();
        for(int i = prev.size() - 2; i >= 0; i--){
            rigm[i] = max(rigm[i+1] - 1, prev[i]);
        }
    }

    long long maxPoints(vector<vector<int>>& points) {
        ll n = points.size(), m = points[0].size();
        vector<vector<ll>> point(n, vector<ll>(m));
        for(int i =0; i < n; i++)
            for(int j = 0; j < m; j++)
                point[i][j] = points[i][j];

        vector<ll> cur, prev, lefm, rigm;


        for(int i = 1; i < n; i++){
            cur = point[i];
            prev = point[i- 1];
            getL(prev, lefm);
            getR(prev, rigm);

            for(int j =0 ; j <m; j++){
                point[i][j] = max(cur[j], cur[j] + max(lefm[j], rigm[j]));
            }
        }
        ll ans = 0;

        for(int i = 0; i < m; i++){
            ans = max(ans, static_cast<long long>(point[n-1][i]));
        }

        return ans;
    }
};