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

    ListNode * reverse(ListNode * head){
        ListNode * prev = NULL, * cur = head, * nxt = head->next;

        while(nxt){
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }

        cur->next = prev;

        return cur;
    }

    ListNode * dit(ListNode * head){
        ListNode * dummy = new ListNode (10);
        ListNode * temp = dummy, * cur = head;
        int car = 0;
        while(cur){
            int value = cur->val;
            int modval = (2 * value) + car;

            car = modval/10;
            int curval = modval%10;
            ListNode * wer = new ListNode(curval);
            temp->next = wer;
            temp = wer;
            cur = cur->next;
        }

        if(car != 0){
            ListNode * qw = new ListNode (car);
            temp->next = qw;

        }

        return dummy->next;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode * revit = reverse(head);

        ListNode * doubleit = dit(revit);

        ListNode * agrevit = reverse(doubleit);

        return agrevit;
    }
};