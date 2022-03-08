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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head==NULL || head->next==NULL || head->next->next==NULL)return false;
        do
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)return true;
            
        }while(fast->next!=NULL && fast->next->next!=NULL);
        return false;
        
    }
};