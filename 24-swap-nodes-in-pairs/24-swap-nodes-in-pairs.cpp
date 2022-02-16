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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL)return head;
        ListNode *prev = NULL, *curr=head, *nxt = NULL;
        int cnt = 0;
        while(cnt<2)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        if(nxt!=NULL)
        {
            ListNode *resthead = swapPairs(nxt);
            head->next = resthead;
        }
        return prev;
    }
};