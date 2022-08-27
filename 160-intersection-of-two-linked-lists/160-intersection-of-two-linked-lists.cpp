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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        int cnt1 = 0, cnt2 = 0;
        while(l1)
            l1 = l1->next, cnt1++;
        while(l2)
            l2 = l2->next, cnt2++;
        if(cnt1>cnt2){
            l1 = headA, l2 = headB;
            int k = cnt1-cnt2;
            while(l1 and k--){
                l1 = l1->next;
            }
            while(l1!=l2)
                l1 = l1->next, l2 = l2->next;
            return l1;
        }
        else{
            l1 = headA, l2 = headB;
            int k = cnt2-cnt1;
            while(l2 and k--){
                l2 = l2->next;
            }
            while(l1!=l2)
                l1 = l1->next, l2 = l2->next;
            return l1;
        }
        return NULL;
    }
};