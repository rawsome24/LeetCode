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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        int cnt = 0;
        while(curr!=NULL && cnt<k)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = nxt;
            cnt++;
        }
        if(nxt!=NULL)
        {
            ListNode *ptr = nxt;
            int l =0;
            while(ptr){ptr=ptr->next; l++;}
            if(l>=k){
                    ListNode *rest_head = reverseKGroup(nxt,k);
                    head->next = rest_head;
            }
            else head->next = nxt;
        }
        return prev;
    }
};