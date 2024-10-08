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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode * t = head, * r = head->next;

        while(r){
            int gcd = __gcd(t->val, r->val);
            ListNode * temp = new ListNode(gcd);

            temp->next = r;
            t->next = temp;

            t = r;
            r = r->next;
        }
        return head;
    }
};