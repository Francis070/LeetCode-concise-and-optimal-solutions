class Solution {
public:

    bool check(char a){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int stirng_len = s.size();

        int left = 0, right = left + k - 1;
        int number_of_vowels = 0, ans = 0;
        while(right < stirng_len){

            if(left == 0){
                for(int i = 0; i < k; i++){
                    if(check(s[i]))
                        number_of_vowels += 1;
                }
                
            }
            else{
                if(check(s[right])){
                    number_of_vowels += 1;
                }
                if(check(s[left - 1]))
                    number_of_vowels -= 1;
            }
            ans = max(ans, number_of_vowels);
            right++;
            left++;
        }

        return ans;
    }
};

// given 

// string s, const k
// strings with 

// case 1 

// s = 'a b c i i i d e f'

// 1 - a b c - 1
// 2 - b c i - 1
// 3 - c i i - 2
// 4 - i i i - 3
// 5 - i i d - 2
// 6 - i d e - 2
// 7 - d e f - 1


// 'a b c i i i d e f'
//  0 1 2 3 4 5 6 7 8

// left
// right = left + k - 1


// left = 3
// right = 3 + 3 - 1 = 5

// int max_vowels = max(max_vowels, number_of_vowels);
// int number_of_vowels = 3

// left = 2
// right = 5



