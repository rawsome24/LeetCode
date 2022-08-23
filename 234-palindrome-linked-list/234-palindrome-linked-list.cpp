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
    ListNode *reverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while(curr!=NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head==NULL || head->next==NULL)return true;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = reverseList(slow->next);
        ListNode *curr = head;
        while(curr!=NULL && rev!=NULL)
        {
            if(curr->val != rev->val)return false;
            rev = rev->next;
            curr = curr->next;
        }
        return true;
    }
};