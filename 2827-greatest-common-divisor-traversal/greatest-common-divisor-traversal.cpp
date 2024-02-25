class DSU{
public:
    unordered_map<int, int> parent;

    DSU(vector<int> x){
        for(int i = 0 ;i < x.size(); i++){
            if(x[i] == 1){
                parent[i] = i;
            }
        }
    }

    int findParent(int num){
        if(parent[num] == num)
            return num;
        
        return parent[num] = findParent(parent[num]);
    }

    void unionByDiv(int a, int b){
        if(parent.find(a) == parent.end())
            parent[a] = a;
        if(parent.find(b) == parent.end())
            parent[b] = b;
        int pa = findParent(a);
        int pb = findParent(b);

        if(pa != pb){
            if(pa < pb){
                parent[pb] = pa;
            }
            else{
                parent[pa] = pb;
            }
        }
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        int mx_ele = *max_element(begin(nums), end(nums));
        int m = mx_ele + 5;
        vector<int> v(m, 0), prime(m, 1);
        
        bool chk = false;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
                chk = true;
            else{
                v[nums[i]] = 1;
            }
        }

        if(chk){
            if(nums.size() == 1)
                return true;
            return false;
        }

        DSU obj(v);

        for(int i = 2; i < m; i++){
            
            if(prime[i] == 1){
                
                for(int j = i; j < m; j+= i){
                    prime[j] = 0;
                    if(v[j] == 1){
                        // cout<<i<<" "<<j<<" ";
                        int parj = obj.findParent(j);
                        // cout<<parj<<endl;
                        if(parj != i){
                            obj.unionByDiv(parj, i);
                            // obj.parent[j] = i;
                        }
                    }
                }
            }
        }

        unordered_set<int> us;
        for(int i = 0; i < m; i++){
            if(v[i] == 1){
                int fp = obj.findParent(i);
                us.insert(fp);
            }
        }

        if(us.size() != 1)
            return false;
        return true;
    }
};