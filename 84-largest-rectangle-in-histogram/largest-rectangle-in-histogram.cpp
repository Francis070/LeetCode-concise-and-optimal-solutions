class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> lnse(n, -1), rnse(n, -1);

        stack<int> st;
        for(int i =0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                rnse[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                lnse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;

        for(int i = 0; i < n; i++){
            int cur = 0;
            cur += (lnse[i] == -1) ? i : (i - lnse[i] - 1);
            cur += (rnse[i] == -1) ? n - i : rnse[i] - i;

            ans = max(ans, heights[i] * cur);
        }

        return ans;
    }
};