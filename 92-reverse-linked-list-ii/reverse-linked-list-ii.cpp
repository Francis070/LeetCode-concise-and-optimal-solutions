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

    ListNode* reverseList(vector<ListNode * > &v, int l, int r ){
        int n = v.size();
        ListNode * head = v[0];
        int i = l, j = l-1;
        v[j]->next = NULL;
        while(j < r-1){
            v[i]->next = v[j];
            i++; j++;
        }

        v[l-1]->next = v[r];
        if(l-2 >= 0)
            v[l-2]->next = v[r-1];
        else
            head = v[r-1];

        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode * > v;

        if(right - left == 0)
            return head;

        ListNode * temp = head;

        while(temp != NULL){
            v.push_back(temp);
            temp = temp->next;
        }

        v.push_back(NULL);

        ListNode * ans = reverseList(v, left, right);
        return ans;
    }
};