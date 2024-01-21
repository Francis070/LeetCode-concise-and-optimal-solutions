class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> st;
        for(int i : arr)
            st.insert(i);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1 ; j < n; j++){
                int a = arr[i], b = arr[j];
                int cnt = 2;
                while(st.find(a + b) != st.end()){
                    int c = a + b;
                    a = b;
                    b = c;
                    cnt++;
                }

                if(cnt >= 3)
                    ans = max(ans, cnt);
            }
        }

        return ans;
    }
};