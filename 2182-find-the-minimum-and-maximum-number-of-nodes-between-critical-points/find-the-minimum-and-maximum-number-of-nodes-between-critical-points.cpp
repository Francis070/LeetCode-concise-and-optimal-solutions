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

    int getMinDist(ListNode * head){
        int res = -1;

        int sl = -1, l = -1;
        int cnt = 0;
        int prev = -1;
        int ans = INT_MAX;
        ListNode * temp = head;
        while(temp != NULL){
            if(sl == -1){
                sl = temp->val;
            }
            if(l == -1)
                l = temp->val;

            if(sl != -1 && l != -1){
                if((l > sl  && l > temp->val) || (l < sl  && l < temp->val)){
                    if(prev != -1){
                        ans = min(ans, cnt - prev);
                    }
                    // cout<<sl<<" "<<l<<" "<<temp->val<<" "<<prev<<endl;

                    prev = cnt;
                }
            }
            sl = l;
            l = temp->val;
            cnt++;
            temp = temp->next;
        }

        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }

    int getMaxDist(ListNode * head){
        int sl = -1, l = -1;
        int cnt = 0;
        int prev = -1;
        int ans = INT_MIN;
        bool chk = false;
        ListNode * temp = head;
        while(temp != NULL){
            if(sl == -1){
                sl = temp->val;
            }
            if(l == -1)
                l = temp->val;

            if(sl != -1 && l != -1){
                if((l > sl  && l > temp->val) || (l < sl  && l < temp->val)){
                    if(chk == false){
                        prev = cnt;
                        chk = true;
                    }
                    else{
                        ans = max(ans, cnt - prev);
                    }
                }
            }
            sl = l;
            l = temp->val;
            cnt++;
            temp = temp->next;
        }

        if(ans == INT_MIN)
            return -1;
        else
            return ans;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans(2);

        int mind = getMinDist(head);
        int maxd = getMaxDist(head);

        ans[0] = mind;
        ans[1] = maxd;

        return ans;
    }
};