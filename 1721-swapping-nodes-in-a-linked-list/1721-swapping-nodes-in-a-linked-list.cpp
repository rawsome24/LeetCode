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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *start = head, *p = head, *q = head;
        int n = k;
        while(n-1) {start=start->next; n--;}
        n = k;
        while(n) {q = q->next; n--;}
        while(q!=NULL)
        {
            q = q->next;
            p = p->next;
        }
        swap(p->val, start->val);
        return head;
    }
};