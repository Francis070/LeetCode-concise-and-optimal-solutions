class Solution {
public:

    bool chk(vector<int>& house, vector<int>& heat, int rad){
        int n = house.size(), m= heat.size();

        int j = 0, i = 0;
        vector<int> hse(n, -1);
        while(i < n && j < m){
            if(house[i] <= heat[j] + rad && house[i] >= heat[j] - rad){
                hse[i] = 1;
                i++;
            }
            else{
                j++;
            }   
        }

        for(int k = 0; k < n; k++)
            if(hse[k] == -1)
                return false;
        
        return true;
    }

    int findRadius(vector<int>& house, vector<int>& heat) {
        int mx = *max_element(house.begin(), house.end());
        int mn = *min_element(house.begin(), house.end());

        sort(house.begin(), house.end());
        sort(heat.begin(), heat.end());


        int s= 0, h = max(heat.back(), house.back()) + 1;

        while(s < h){
            int mid = s + (h - s)/2;

            if(chk(house, heat, mid)){
                h = mid;
            }
            else
                s = mid + 1;
        }

        return h;
    }
};