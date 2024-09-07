class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int currentGas = 0, cst = 0;
        vector<int> prefixSum(n, 0);
        for(int i = 0; i < n; i++){currentGas += gas[i]; cst += cost[i]; prefixSum[i] = gas[i] - cost[i];}

        if(cst > currentGas)
            return -1;
        int ans = -1;
        int total = 0;
        for(int i =0 ; i < n; i++){
            if(total + prefixSum[i] < 0){
                ans = -1; 
                total = 0;
            }
            else{
                total += prefixSum[i];
                if(ans == -1)
                    ans = i;
            }
        }
        
        return ans;
    }
};