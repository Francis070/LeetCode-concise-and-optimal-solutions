class Solution {
public:
    int countCollisions(string dir) {
        int n =  dir.size();
        stack<char> st;
        int ans = 0;

        for(int i = 0;i < n; i++){

            if(dir[i] == 'R')
                st.push('R');

            else if(dir[i] == 'S'){
                while(!st.empty() && st.top() == 'R'){
                    ans += 1;
                    st.pop();
                }
                st.push('S');
            }

            else{
                if(!st.empty()){
                    
                    if(st.top() == 'R'){
                        ans += 2;
                        st.pop();
                    }
                    else if(!st.empty() ){
                        ans += 1;
                        // st.pop();
                    }

                    st.push('S');

                }
            }

            // cout<<i<<" "<<ans<<endl;
        }

        while(!st.empty()){
            char x = st.top();
            st.pop();
            while(!st.empty() && st.top() == 'R' && x == 'S'){
                ans++;
                st.pop();
            }
        }

        return ans;
    }
};