class Solution {
public:

    // int find_max(int x, int y, vector<vector<int>> & mat){
    //     int res = 1;

    //     for(int i = x-1; i >= 0; i--){
    //         for(int j = y-1; j >= 0; j--){
                
    //             int exp = 0;
    //             if((x - i) != 0 && (y - j) != 0)
    //                 exp = ((x - i) * (y - j));
    //             else{
    //                 exp = max(x - i, y - j);
    //             }


    //             int cur = mat[x][y] - mat[x][j] - mat[i][y] + mat[i][j];

    //             if(cur == exp)
    //                 res = max(res, cur);
    //         }
    //     }
    //     for(int i = x; i > 0; i--){
    //         int exp = (x - i + 1) * (y + 1);
    //         int cur = mat[x][y] - mat[i-1][y];
    //         if(exp == cur)
    //             res = max(res, cur);
    //     }
    //     for(int j = y; j > 0; j--){
    //         int exp = (y - j + 1) * (x + 1);
    //         int cur = mat[x][y] - mat[x][j - 1];
    //         if(exp == cur)
    //             res = max(res, cur);
    //     }
    //     if(mat[x][y] == ((x + 1) * (y + 1)))
    //         res = max(res, mat[x][y]);
        
    //     return res;
    // }

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

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        vector<int> hg(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == '0'){
                    hg[j] = 0;
                }
                else{
                    hg[j]++;
                }
            }
            int cur = largestRectangleArea(hg);
            ans = max(ans, cur);
        }

        return ans;
    }
};