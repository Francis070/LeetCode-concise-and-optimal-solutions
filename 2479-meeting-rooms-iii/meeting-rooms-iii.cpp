#define ll long long
class Solution {
public:

    static bool comp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        
        int ms = meetings.size();

        sort(meetings.begin(), meetings.end(), comp);

        priority_queue<ll, vector<ll>, greater<ll>> available;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> used;

        for(int i =0; i< n; i++)
            available.push(i);

        for(int i = 0; i < ms; i++){
             while(!used.empty() && used.top().first <= meetings[i][0]){
                available.push(used.top().second);
                used.pop();
            }
            if(!used.empty()){
                if(used.top().first <= meetings[i][0]){
                    pair<ll, ll> got = used.top();
                    used.pop();
                    used.push({meetings[i][1], got.second});
                    rooms[got.second]++;
                }
                else{
                    if(!available.empty()){
                        ll got = available.top();
                        used.push({meetings[i][1], got});
                        available.pop();
                        rooms[got]++;
                    }
                    else{
                        pair<ll, ll> got = used.top();
                        ll diff = meetings[i][1]- meetings[i][0];
                        used.pop();
                        used.push({got.first + diff , got.second});
                        rooms[got.second]++;
                    }
                }
            }
            else{
                ll got = available.top();
                available.pop();
                used.push({meetings[i][1], got});
                rooms[got]++;
            }
        }
        ll max_used = *max_element(rooms.begin(), rooms.end());

        for(int i = 0; i < n; i++)
            if(rooms[i] == max_used)
                return i;

        return 0;
    }
};