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

    ListNode * reverse(ListNode * s){
        ListNode * a = NULL, *b = s, *c = s->next;

        while(c){
            b->next = a;
            a = b;
            b = c;
            // if(c != NULL)
                c = c->next;
        }
        b->next = a;
        ListNode * r = b;
        while(r)
        {
            cout<<r->val<<" ";
            r = r->next;
        }
        return b;
    }

    bool isPalindrome(ListNode* head) {

        if(head->next == NULL)  
            return true;

        ListNode * s = head, *f = head;

        while(f){
            s = s->next;
            if(f->next == NULL)
                break;
            f = f->next->next;
        }

        ListNode * e = reverse(s);
        ListNode * a = head, *b = e;
        while(a && b){
            if(a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }

        return true;

    }
};