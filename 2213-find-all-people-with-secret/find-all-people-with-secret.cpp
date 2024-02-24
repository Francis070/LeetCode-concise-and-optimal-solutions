class DSU{
public:
    vector<int> parent, knows;

    DSU(int n, int fs){
        parent.resize(n);
        knows.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            knows[i] = 0;
        }
        knows[0] = 1;
        knows[fs] = 1;
    }

    //find parent
    int findParent(int x){
        if(parent[x] == x){
            return x;
        }

        parent[x] = findParent(parent[x]);

        return parent[x];
    }

    //union by size
    void unionByKnown(int u, int v){
        int up = findParent(u);
        int vp = findParent(v);

        if(up != vp){
            if(knows[up] == 1){
                parent[vp] = up;
                knows[vp] = 1;
            }
            else if(knows[vp] == 1){
                parent[up] = vp;
                knows[up] = 1;
            }
            else{
                parent[up] = vp;
                knows[up] = 0;
                knows[vp] = 0;
            }
        }
    }
    
    void reset(int x){
        parent[x] = x;
        knows[x] = 0;
    }
};

class Solution {
public:

    /*static bool comp(vector<int> & a, vector<int> &b){
        return (a[2] <= b[2]);
    }*/

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knows(n, 0);
        knows[0] = 1;
        knows[firstPerson]= 1;
    
        DSU *obj = new DSU(n, firstPerson);
        obj->unionByKnown(0, firstPerson);

        // sort(meetings.begin(), meetings.end(), comp);
        map<int, vector<pair<int, int>>> mp;

        for(int i =0 ; i < meetings.size(); i++){
            int x = meetings[i][0], y = meetings[i][1], t = meetings[i][2];

            mp[t].push_back({x, y});
        }

        for(auto & x : mp){
            for(auto p : x.second){
                obj->unionByKnown(p.first, p.second);
            }
            for(auto p : x.second){
                int prt = obj->findParent(p.first);
                if(obj->knows[prt] == 0){
                    obj->reset(p.first);
                    obj->reset(p.second);
                }
            }
            for(auto p : x.second){
                // cout<<p.first<<" "<<p.second<<" ";
                int prt = obj->findParent(p.first);
                // cout<<prt<<" "<<obj->knows[prt]<<endl;
                if(obj->knows[prt] == 0){
                    obj->reset(p.first);
                    obj->reset(p.second);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int prt = obj->findParent(i);
            if(obj->knows[prt] == 1)
                ans.push_back(i);
        }
        
        return ans;
    }
};