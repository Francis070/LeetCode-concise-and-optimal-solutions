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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tot_ele = 0;

        ListNode * temp = head;

        while(temp != NULL){
            tot_ele++;
            temp = temp->next;
        }

        int pos = tot_ele - n;

        int k = 0;
        temp = head;

        if(pos == 0){
            return temp->next;
        }

        for(int i =0; i < pos - 1; i++){
            temp = temp->next;
        }

        //delete it
        temp->next = temp->next->next;
        // cout<<temp->val;

        return head;
    }
};