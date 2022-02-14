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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1=l1,*ptr2=l2;
        int cnt1=0,cnt2=0,carry=0;
        while(ptr1){cnt1++;ptr1=ptr1->next;}
        while(ptr2){cnt2++; ptr2=ptr2->next;}
        ptr1=l1; ptr2=l2;
        if(cnt1!=cnt2)
        {
            if(cnt1>cnt2)
            {
                while(ptr2->next)
                    ptr2=ptr2->next;
                while(cnt1-cnt2)
                {
                    ListNode *zero = new ListNode(0);
                    ptr2->next = zero;
                    ptr2 = zero;
                    cnt2++;
                }
            }
            else
            {
                while(ptr1->next)
                    ptr1=ptr1->next;
                while(cnt2-cnt1)
                {
                    ListNode *zero = new ListNode(0);
                    ptr1->next = zero;
                    ptr1 = zero;
                    cnt1++;
                }
            }
        }
        ptr1=l1; ptr2=l2;
        if(cnt1==cnt2)
        {
            while(ptr1)
            {
                int sum = ptr1->val+ptr2->val;
                if(carry>0)sum+=carry;
                carry = sum>=10?sum/10:0;
                ptr1->val = sum%10;
                ptr1=ptr1->next;
                ptr2 = ptr2->next;
            }
            if(carry)
            {
                ListNode *last = new ListNode(carry);
                ptr1 = l1;
                while(ptr1->next)
                    ptr1=ptr1->next;
                ptr1->next = last;
            }
            return l1;
        }
        return l1;
        
    }
};