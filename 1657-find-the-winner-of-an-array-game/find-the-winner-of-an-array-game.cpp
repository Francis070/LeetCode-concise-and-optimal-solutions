class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int mx = *max_element(arr.begin(), arr.end());

        vector<int> nge(n, -1), ge(n, -1);
        stack<int> st;

        for(int i = 0 ; i < n; i++){
            // if(arr[i] == mx)
            //     break;
            // else{
                while(!st.empty() && arr[st.top()] < arr[i]){
                    nge[st.top()] = i;
                    st.pop();
                }

                st.push(i);
            // }
        }
        int cur = arr[0];
        ge[0] = INT_MAX;
        for(int i =1; i< n; i++){
            ge[i] = cur;
            cur = max(cur, arr[i]);
        }

        for(int i =0; i< n; i++){
            if(arr[i] != mx){
                // cout<<ge[i]<<" "<<nge[i]<<endl;
                if((ge[i] < arr[i] && (nge[i] - i - 1) >= k-1) || (ge[i] == INT_MAX && (nge[i] - i - 1) >= k)){
                    return arr[i];
                }
            }
            else
                break;
        }

        return mx;
    }
};