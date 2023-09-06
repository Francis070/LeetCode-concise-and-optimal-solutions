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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode * temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }
        int div = n/k, rem = n%k;
        vector<int> ref(k, div);
        for(int i = 0; i < rem; i++)
            ref[i]++;
        
        vector<ListNode*> res(k, NULL);

        ListNode * st = head, *en = head, *mid;
        int cnt = 1;
        for(int i = 0; i < k; i++){
            if(ref[i] > 0){
                while(cnt + 1 <= ref[i]){
                    en = en->next;
                    cnt++;
                }
                res[i] = st;
                mid = en;
                en = en->next;
                mid->next = NULL;
                st = en;
                cnt = 1;
            }
        }

        return res;
    }
};