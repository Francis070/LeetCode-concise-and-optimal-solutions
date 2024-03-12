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

    ListNode * getnh(ListNode * head, bool &chk){
        unordered_map<int, ListNode *> um;
        ListNode * temp = head;
        int runsum = 0;
        while(temp != NULL){
            runsum += temp->val;

            if(um.find(runsum) != um.end()){
                ListNode * left = um[runsum];
                left->next = temp->next;
                chk = true;
                break;
            }
            else if (runsum == 0){
                head = temp->next;
                chk = true;
                break;
            }

            um[runsum ] = temp;
            temp = temp->next;
        }

        return head;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        bool chk = false;

        ListNode * temp = getnh(head, chk);

        while(chk){
            chk = false;
            temp = getnh(temp, chk);
        }

        return temp;
    }
};