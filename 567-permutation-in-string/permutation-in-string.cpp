class Solution {
public:

    bool comp(map<char, int> m1, map<char, int> m2){
        for(auto & x : m1)
            if(m2[x.first] != x.second)
                return false;

        for(auto & x : m2)
            if(m1[x.first] != x.second)
                return false;

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        map<char, int> mp;
        for(char c : s1)
            mp[c]++;

        int s = 0, e = 0;

        map<char, int> ic;
        while(e < n){
            ic[s2[e]]++;

            while(s <= e && ic[s2[e]] > mp[s2[e]]){
                ic[s2[s]]--;
                s++;
            }

            if(comp(ic, mp)){
                return true;
            }

            e++;
        }

        return false;
    }
};