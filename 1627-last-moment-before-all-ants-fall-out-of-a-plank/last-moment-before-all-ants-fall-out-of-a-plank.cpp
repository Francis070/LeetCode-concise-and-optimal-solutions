class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int n1 = left.size(), n2 = right.size();
        int ans = 0;
        for(int i= 0; i < n1; i++){
            ans = max(ans, left[i]);
        }

        for(int i =0; i < n2; i++){
            ans = max(ans, n - right[i]);
        }

        return ans;
    }
};


// 0  1    3  4

