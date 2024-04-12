class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lm (n, -1), rm(n, -1);

        stack<int> st;
        for(int i =0; i <n; i++){
            while(!st.empty() && height[i] >= height[st.top()]){
                st.pop();
            }

            // cout<<i<<" "<<st.size()<<endl;

            if(st.empty()){
                lm[i] = -1;
            }
            else{
                if(lm[st.top()] != -1)
                    lm[i] = lm[st.top()];
                else
                    lm[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && height[i] >= height[st.top()]){
                st.pop();
            }

            if(st.empty()){
                rm[i] = -1;
            }
            else{
                if(rm[st.top()] != -1)
                    rm[i] = rm[st.top()];
                else
                    rm[i] = st.top();
            }

            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            // cout<<lm[i]<<" "<<rm[i]<<" ";
            if(lm[i] != -1 && rm[i] != -1){
                // cout<<(min(height[lm[i]], height[rm[i]]) - height[i]);
                ans += (min(height[lm[i]], height[rm[i]]) - height[i]);
            }
            // cout<<endl;
        }

        return ans;
    }
};