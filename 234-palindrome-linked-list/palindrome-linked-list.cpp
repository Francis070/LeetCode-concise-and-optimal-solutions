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

    ListNode * rev(ListNode * head){
        ListNode * prev = NULL, *mid = head, *nxt = head->next;

        while(mid->next){
            mid->next = prev;
            prev = mid;
            mid = nxt;
            nxt = nxt->next;
        }

        mid->next = prev;
        return mid;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return head;

        ListNode * fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * ulta = rev(slow->next);
        ListNode * t1 = head, *t2 = ulta;
        while(t1 && t2){
            if(t1->val != t2->val)
                return false;
            else{
                t1 = t1->next;
                t2 = t2->next;
            }
        }

        return true;
    }
};