class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int init = 0;
        vector<double> avg;
        for(int i = 0; i < n; i++){
            int er = max(init, customers[i][0]) + customers[i][1];
            init = er;
            avg.push_back(er - customers[i][0]);
        }

        double ans = 0;
        for(double cur : avg)
            ans += cur;

        return ans/n;
    }
};