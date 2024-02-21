#define ll long long

class Solution {
public:

    vector<int> get_binary(int num){
        vector<int> res;

        while(num > 0){
            if((num & 1) == 1){
                res.push_back(1);
            }
            else{
                res.push_back(0);
            }
            num >>= 1;
        }

        // reverse(res.begin(), res.end());
        return res;
    }

    vector<ll> get_setbits(int num){
        ll bitnum = 2, bitHalf = bitnum/2;

        vector<ll> res;
        int temp = num;
        while(temp > 0){

            int value = 0;
            int quo = num/bitnum;
            int rem = num%bitnum;
            value += (bitHalf * quo);

            if(rem >= bitHalf){
                value += (rem - bitHalf + 1);
            }

            res.push_back(value);
            bitnum *= 2;
            bitHalf *= 2;
            temp >>= 1;
        }

        // reverse(res.begin(), res.end());

        return res;
    }

    ll get_finalvalue(vector<int> v){
        ll res = 0;

        ll exp = 0;

        for(int i= 0; i< v.size(); i++, exp++){
            res = res + v[i]*(pow(2, exp));
        }

        return res;
    }

    int rangeBitwiseAnd(int left, int right) {
        vector<int> bin_left = get_binary(left);
        vector<int> bin_right = get_binary(right);

        vector<ll> setbits_left = get_setbits(left);
        vector<ll> setbits_right = get_setbits(right);

        int min_size = min(bin_left.size(), bin_right.size());

        vector<int> result(min_size);

        int diff = right - left;

        for(int i = 0; i < min_size; i++){
            if(bin_left[i] + bin_right[i] == 2 && (setbits_right[i] - setbits_left[i] == diff)){
                result[i] = 1;
            }
        }

        // for(int i=0; i < bin_left.size(); i++){
        //     cout<<bin_left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i < bin_right.size(); i++){
        //     cout<<bin_right[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i < setbits_left.size(); i++){
        //     cout<<setbits_left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i < setbits_right.size(); i++){
        //     cout<<setbits_right[i]<<" ";
        // }

        ll final_value = get_finalvalue(result);

        return final_value;
    }
};