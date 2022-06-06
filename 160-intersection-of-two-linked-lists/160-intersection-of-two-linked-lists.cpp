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
        if(headA==NULL || headB==NULL)return NULL;
        
        int cnt1=0,cnt2=0;
        ListNode *currA = headA;
        ListNode *currB = headB;
        while(currA!=NULL){cnt1++;currA=currA->next;}
        while(currB!=NULL){cnt2++;currB=currB->next;}
        currA = headA; currB=headB;
        if(cnt1>=cnt2)
        {
            for(int i=0; i<abs(cnt1-cnt2); i++)
                currA=currA->next;
        }
        else
        {
            for(int i=0; i<abs(cnt2-cnt1); i++)
                currB = currB->next;
        }
            while(currA!=NULL && currB!=NULL)
            {
                if(currA == currB)
                    return currA;
                currA=currA->next;
                currB=currB->next;
            }
            return NULL;        
        
    }
};