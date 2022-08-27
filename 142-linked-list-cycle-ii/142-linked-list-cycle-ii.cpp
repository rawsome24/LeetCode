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
    ListNode* checkCycle(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return fast;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = checkCycle(head);
        if(fast){
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return NULL;
        
    }
};