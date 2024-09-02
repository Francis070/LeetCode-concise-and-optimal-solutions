#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        ll sum = 0;
        for(int i : chalk) sum += i;

        int tot = k%sum;
        
        for(int i = 0; i < n; i++){
            if(tot - chalk[i] < 0){
                return i;
            }
            else{
                tot -= chalk[i];
            }
        }

        return -1;
    }
};