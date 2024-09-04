class Solution {
public:

    int gpos(int pos, int dir, int len, vector<int> & v){
        int p = lower_bound(v.begin(), v.end(), pos) - v.begin();

        int des = pos + (dir * len);

        if(dir > 0){
            if(p == v.size() || (v[p] == pos && p + 1 >= v.size()))
                return des;
            else{
                if(des < v[p])
                    return des;
                else{
                    return v[p] - 1;
                }
            }
        }
        else{
            if((p == v.size() && des > v.back()) || (p != v.size() && v[p] == pos && p - 1 < 0) || p == 0){
                return des;
            }
            else{
                if(des > v[p - 1])
                    return des;
                else{
                    return v[p-1] + 1;
                }
            }
        }
    }

    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        
        map<int, vector<int>> ox, oy;

        int n = o.size();
        int m = c.size();

        for(int i = 0; i < n; i++){
            ox[o[i][0]].push_back(o[i][1]);
            oy[o[i][1]].push_back(o[i][0]);
        }

        for(auto & r : ox)
            sort(r.second.begin(), r.second.end());
        for(auto & r : oy)
            sort(r.second.begin(), r.second.end());
        int ans =0;
        int dx = 0, dy = 1;
        int x = 0, y = 0;
        for(int i = 0; i < m; i++){
            if(c[i] == -1 || c[i] == -2){
                if(c[i] == -1){
                    if(dx == 0){
                        if(dy > 0)
                            dx = 1;
                        else 
                            dx = -1;
                        dy = 0;
                    }
                    else{
                        if(dx > 0)
                            dy = -1;
                        else 
                            dy = 1;
                        dx = 0;
                    }
                }
                else{
                    if(dx == 0){
                        if(dy > 0)
                            dx = -1;
                        else 
                            dx = 1;
                        dy = 0;
                    }
                    else{
                        if(dx > 0)
                            dy = 1;
                        else 
                            dy = -1;
                        dx = 0;
                    }
                }
            }
            else{
                int len = c[i];

                if(dx == 0){
                    bool chk = false;
                    if(ox.find(x) != ox.end()){
                        chk = true;
                    }

                    if(chk){
                        int fy = gpos(y, dy, len, ox[x]);
                        y = fy;
                    }
                    else{
                        y += (dy) * len;
                    }
                    
                }   
                else{
                    bool chk = false;
                    if(oy.find(y) != oy.end()){
                        chk = true;
                    }

                    if(chk){
                        int fx = gpos(x, dx, len, oy[y]);
                        x = fx;
                    }
                    else{
                        x += (dx) * len;
                    }
                    
                }
            }
            
            int er = (x * x) + (y * y);
            ans = max(ans, er);
        }

        return ans;

    }
};