class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y >= x)
            return y - x;

        unordered_map<int, int> mp;
        mp[x] = 1;
        int low = 1, high = x + (x - y);

        queue<int> q;
        int l = 0;
        q.push(x);

        while(!q.empty()){
            int t = q.size();
            
            l++;
            while(t--){
                int x = q.front();
                q.pop();
                if(x + 1 == y || x - 1 == y || (x %5 == 0 && x/5 == y) || (x%11 == 0 && x /11 == y)){
                    return l;
                }

                if(x + 1 <= high && mp.find(x + 1) == mp.end()){
                    q.push(x + 1);
                    mp[x + 1] = 1;
                }
                if(x - 1 >= 1 && mp.find(x - 1) == mp.end()){
                    q.push(x - 1);
                    mp[x - 1] = 1;
                }
                if(x % 5 == 0 && mp.find(x/5) == mp.end()){
                    q.push(x/5);
                    mp[x/5] = 1;
                }
                if(x % 11 == 0 && mp.find(x/11) == mp.end()){
                    q.push(x/11);
                    mp[x/11] = 1;
                }
            }
        }

        return -1;
    }
};