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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> us;
        for(int i : nums)
            us.insert(i);

        ListNode * temp = head, * prev = NULL;
        int cnt = 0;
        while(temp != NULL){
            int cur = temp->val;

            if(us.find(cur) != us.end()){
                if(prev == NULL){
                    head = temp->next;
                    // temp = temp->next;
                }
                else{
                    prev->next = temp->next;
                    // temp = temp->next;
                }
            }
            else{
                if(cnt == 0){
                    prev = temp;
                }
                else{
                    prev = prev->next;
                }
                cnt++;
            }

            temp = temp->next;
        }

        return head;
    }
};