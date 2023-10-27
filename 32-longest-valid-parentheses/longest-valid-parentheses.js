/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let n = s.length;

    let st = [];
    let ans = 0;
    for(let i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            let emp = st.length;
            if(emp > 0 && s[st[st.length - 1]] == '(')
                st.pop();
            else    
                st.push(i);

            if(st.length == 0)
                ans = Math.max(ans, i + 1);
            else
                ans = Math.max(ans, i - st[st.length - 1]);
        }
    }

    return ans;
};