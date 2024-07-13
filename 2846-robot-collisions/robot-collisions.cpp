class robot {
public:
    int pos;
    int health; 
    char dir;

    robot(int po, int hel, char di){
        this->pos = po;
        this->health = hel;
        this->dir = di;
    }
};

class Solution {
public:

    static bool comp(robot * a, robot * b){
        if(a->pos < b->pos)
            return true;
        else 
            return false;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        stack<robot *> st;
        vector<robot *> v;
        for(int i = 0; i < n; i++){
            robot * cur = new robot(positions[i], healths[i], directions[i]);
            v.push_back(cur);
        }

        sort(begin(v), end(v), comp);

        for(int i =0; i <n ; i ++){
            robot * cur = v[i];

            if(!st.empty()){
                if(cur->dir == 'R'){
                    st.push(cur);
                }
                else{
                    if(st.top()->dir == 'R'){
                        if(st.top()->health > cur->health){
                            st.top()->health--;
                        }
                        else{
                            if(st.top()->health == cur->health)
                                st.pop();
                            else{
                                
                                while(!st.empty() && st.top()->dir == 'R' && st.top()->health < cur->health){
                                    st.pop();
                                    cur->health --;
                                }

                                // if(cur.health > 0){
                                if(!st.empty() && st.top()->dir == 'R'){
                                    if(st.top()->health == cur->health){
                                        st.pop();
                                    }
                                    else{
                                        st.top()->health --;
                                    }
                                }
                                else{
                                    st.push(cur);
                                }
                                // }
                                // else{

                                // }

                                // st.push(cur);
                            }
                        }
                    }
                    else{
                        st.push(cur);
                    }
                }
            }
            else{
                st.push(cur);
            }
        }

        unordered_map<int, int> uph;

        while(!st.empty()){
            uph[st.top()->pos] = st.top()->health;
            st.pop();
        }

        vector<int> hel;
        for(int i = 0; i < n; i++){
            if(uph.find(positions[i]) != uph.end()){
                hel.push_back(uph[positions[i]]);
            }
        }

        return hel;
    }
};