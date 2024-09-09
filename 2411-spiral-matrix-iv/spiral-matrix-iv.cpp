/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // int cnt = 0;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int dx = 1, dy = 0;
        ListNode * t = head;
        int x = 0, y = 0, rx = n, ry = m - 1;
        int cnt = 0;
        while(t){
            
            int v= t->val;
            ans[y][x] = v;
            // cout<<y<<" "<<x<<endl;
            if(dx != 0){
                if(cnt + 1 == rx){
            
                    if(dx > 0){
                        dy = 1;
                    }
                    else
                        dy = -1;
                    dx = 0;

                    cnt = -1;
                    rx--;
                }
                
                
            }
            else{
                if(cnt + 1 == ry){
                    if(dy > 0)
                        dx = -1;
                    else 
                        dx = 1;
                    dy = 0;
                    cnt = -1;
                    ry--;
                }
                
            }
            x += dx; y += dy;
            

            // if(x == rx || y == ry){
            //     //change dir
                
            // }

            cnt++;
            t = t->next;
        }

        return ans;
    }
};