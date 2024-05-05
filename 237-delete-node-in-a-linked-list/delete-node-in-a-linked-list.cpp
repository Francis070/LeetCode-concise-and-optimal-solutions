/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * curnxt = node->next;
        ListNode * cur = node;
        while(curnxt != NULL){
            cur->val = curnxt->val;
            cur =curnxt;
            curnxt = curnxt->next;
        }

        curnxt = node->next;
        cur = node;
        while(curnxt->next != NULL){
            cur =curnxt;
            curnxt = curnxt->next;
        }
        cur->next = NULL;
    }
};