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
    ListNode* reverseLL(ListNode *head){
        if(head==NULL or head->next==NULL)
            return head;
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<slow->val<<endl;
        ListNode *rev = reverseLL(slow);
        // cout<<rev->val<<endl;
        slow = head;
        while(rev){
            if(rev->val!=slow->val)
                return false;
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};