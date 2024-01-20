class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;

        vector<int> left(n, 0), right(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
                left[i] = -1;
            }
            else{
                left[i] = st.top();
                st.push(i);
            }
        }

        while(!st.empty())
            st.pop();

        for(int i= n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
                right[i] = -1;
            }
            else{
                right[i] = st.top();
                st.push(i);
            }
        }

        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            long long ls = 0, rs = 0;
            
            if(left[i] == -1)
                ls += i;
            else
                ls += i - left[i] - 1;
            
            if(right[i] == -1)
                rs += n - i - 1;
            else    
                rs += right[i] - i - 1;
            ls++; rs++;
            // cout<<left[i]<<" "<<right[i]<<" "<<(ls * rs)<<endl;
            ans = (ans + (ls * rs * arr[i])%mod)%mod;
        }

        return ans%mod;
    }
};