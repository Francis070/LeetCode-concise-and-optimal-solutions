class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();

        set<pair<int, int>> us;
        int x = 0, y = 0;
        us.insert({0, 0});
        for(int i = 0; i < n; i++){
            if(path[i] == 'N'){
                y++;
                if(us.find({x, y}) != us.end()){
                    return true;
                }
                us.insert({x, y});
            }
            else if(path[i] == 'E'){
                x++;
                if(us.find({x, y}) != us.end()){
                    return true;
                }
                us.insert({x, y});
            }
            else if(path[i] == 'W'){
                x--;
                if(us.find({x, y}) != us.end()){
                    return true;
                }
                us.insert({x, y});
            }
            else{
                y--;
                if(us.find({x, y}) != us.end()){
                    return true;
                }
                us.insert({x, y});
            }
        }
        return false;
    }
};