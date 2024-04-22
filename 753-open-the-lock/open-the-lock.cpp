class Solution {
public:

    int bfs(string src, string dest, unordered_set<string> de){
        unordered_set<string > vis;

        queue<string> q;
        vis.insert(src);
        q.push(src);
        for(auto & s : de){
            vis.insert(s);
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            bool got = false;
            while(sz--){
                string cur = q.front();

                q.pop();
                // cout<<cur<<" ";
                if(cur == dest){
                    got = true;
                    break;
                }

                for(int i =0; i < 4; i++){
                    string temp = cur;
                    // + 1
                    string t1, t2;
                    char c = temp[i];
                    if(c == '0' || c == '9'){
                        int no = c - '0';
                        int no1, no2;
                        if(no == 0){
                            no1 = 1; no2 = 9;
                        }
                        else{
                            no1 = 0; no2 = 8;
                        }

                        t1 = temp.substr(0, i) + to_string(no1)+ temp.substr(i + 1, 4 - i - 1);
                         t2 = temp.substr(0, i) + to_string(no2)+ temp.substr(i + 1, 4 - i - 1);
                    }
                    // - 1
                    else{
                        int no = c - '0';
                        int no1 = no + 1, no2 = no - 1;

                         t1 = temp.substr(0, i) + to_string(no1)+ temp.substr(i + 1, 4 - i - 1);
                         t2 = temp.substr(0, i) + to_string(no2)+ temp.substr(i + 1, 4 - i - 1);
                    }

                    if(vis.find(t1) == vis.end()){
                        vis.insert(t1);
                        q.push(t1);
                    }
                    if(vis.find(t2) == vis.end()){
                        vis.insert(t2);
                        q.push(t2);
                    }
                }
            }
            // cout<<endl;
            
            if(got)
                return ans;
            else
                ans++;
        }

        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> de;
        for(string s : deadends){
            de.insert(s);

        }
        if(de.find("0000") != de.end())
            return -1;
        int ans= bfs("0000", target , de);

        return ans;
    }
};