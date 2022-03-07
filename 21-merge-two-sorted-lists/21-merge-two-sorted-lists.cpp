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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode *start=NULL,*end=NULL,*p=list1,*q = list2;
        if(p->val<=q->val){
            start = list1; end = list1;
            p = p->next;
        }
        else {
            start = list2; end = list2;
            q = q->next;
        }
        while(p!=NULL&&q!=NULL)
        {
            if(q->val<=p->val)
            {
                end->next = q;
                end = q;
                q = q->next;
            }
            else
            {
                end->next = p;
                end = p;
                p = p->next;
            }
        }
        if(p==NULL)end->next = q;
        else  end->next = p;
        return start;
    }
};