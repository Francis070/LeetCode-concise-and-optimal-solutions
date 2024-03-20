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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * ta = NULL, * tb = NULL;

        int pos = 0;
        ListNode * temp = list1;
        
        while(temp){
            if(a - 1 == pos){
                ta = temp;
            }
            if(b == pos){
                tb = temp;
            }

            temp = temp->next;
            pos++;
        }

        ta->next = list2;
        temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = tb->next;

        return list1;
    }
};