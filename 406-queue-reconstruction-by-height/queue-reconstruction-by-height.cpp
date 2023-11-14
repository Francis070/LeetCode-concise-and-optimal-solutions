class Solution {
public:

    static bool comp(vector<int> a, vector<int> b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        else
            return a[1] < b[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();

        // vector<vector<int>> temp (n, vector<int>(2));
        vector<vector<int>> temp = people;

        sort(temp.begin(), temp.end(), comp);

        for(int i = 0; i < n; i++){
            vector<int> cur = temp[i];
            int val = cur[0], cnt = cur[1];
            int er = 0;
            for(int j = i-1; j >= 0; j--){
                if(temp[j][0] >= val)
                    er++;
            }
            if(er > cnt){
                int prev = i-1, abhi = i;
                while(er > cnt){
                    vector<int> buc = temp[prev];
                    temp[prev] = temp[abhi];
                    temp[abhi] = buc;
                    er--;
                    prev--;
                    abhi--;
                }
            }
        }

        return temp;
    }
};