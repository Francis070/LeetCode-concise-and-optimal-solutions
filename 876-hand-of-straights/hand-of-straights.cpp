class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize != 0){
            return false;
        }

        sort(hand.begin(), hand.end());
        for(int i : hand)
            cout<<i<<" ";
        map<int, int> mp;
        for(int i : hand) mp[i]++;
        int tc = 0;
        for(int i = 0; i < n; i++){
            if(mp.count(hand[i]) == 1){
                int val = hand[i];
                int cnt = 0;
                while(mp.count(val) && cnt < groupSize){
                    
                    if(mp[val] == 1){
                        mp.erase(val);
                    }
                    else
                        mp[val]--;
                    val++;
                    cnt++;
                }

                if(cnt == groupSize){
                    tc++;
                }
            }
        }
        cout<<endl<<tc;
        if(tc == 0)
            return false;
        if(n/groupSize == tc)
            return true;
        return false;
    }
};