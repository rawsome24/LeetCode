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
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode *head1 = l1, *head2 = l2;
        int carry = 0;
        ListNode *head = NULL, *tail = NULL;
        while(head1 and head2){
            cout<<carry<<endl;
            int value = (head1->val+head2->val+carry)%10;
            carry = (head1->val+head2->val+carry)/10;
            if(head==nullptr){
                ListNode *temp = new ListNode (value);
                head = temp;
                tail = temp;
            }
            else{
                ListNode *temp = new ListNode (value);
                tail->next = temp;
                tail = tail->next;
            }
            head1 = head1->next;
            head2 = head2->next;
            
        }
        while(head1){
            int value = (head1->val+carry)%10;
            carry = (head1->val+carry)/10;
            ListNode *temp = new ListNode (value);
            tail->next = temp;
            tail = tail->next;
            head1 = head1->next;
        }
        while(head2){
            int value = (head2->val+carry)%10;
            carry = (head2->val+carry)/10;
            ListNode *temp = new ListNode (value);
            tail->next = temp;
            tail = tail->next;
            head2 = head2->next;
        }
        if(carry){
            ListNode *temp = new ListNode (carry);
            tail->next = temp;
            tail = tail->next;
        }
        return head;
    }
};