/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let n = s.length;
    // console.log(len);
    let ans = 0;
    let ans_str =  '';
    for(let i = 0; i < n; i++){
        //for odd length
        let cur = 1, x = i-1, y = i + 1;

        while(x >= 0 && y < n && s[x] == s[y]){
            cur += 2;
            x--; 
            y++;
        }

        if(cur > ans){
            ans = cur;
            ans_str = s.slice(++x, y);
        }

        // for even length
        cur = 0; x = i-1; y = i;
        while(x >= 0 && y < n && s[x] == s[y]){
            cur += 2;
            x--; y++;
        }
        if(cur > ans){
            ans = cur;
            ans_str = s.slice(++x, y);
        }
    }

    return ans_str;
};