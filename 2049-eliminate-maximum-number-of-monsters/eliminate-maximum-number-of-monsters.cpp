class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);

        for(int i = 0; i < n; i++)
            time[i] = (1.0 * dist[i])/speed[i];

        sort(time.begin(), time.end());

        // if(n > 1){
        //     int pos1 = time[0].second, pos2  = time[1].second;
            
        //     if(dist[])
        // }

        // for(auto &i : time)
        //     cout<<i.first<<" ";

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(time[i] > cnt){
                cnt++;
            }
            else
                break;
        }

        return cnt;
    }
};