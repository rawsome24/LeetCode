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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *os = NULL, *oe = NULL, *es = NULL, *ee=NULL;
        int i=1;
        for(auto *curr=head; curr!=NULL; curr=curr->next){
            if(i%2){
                if(os==NULL){
                    ListNode *temp = new ListNode(curr->val);
                    os=temp;
                    oe=os;
                }
                else{
                    oe->next = curr;
                    oe = oe->next;
                }
            }
            else{
                if(es==NULL){
                    ListNode *temp = new ListNode(curr->val);
                    es=temp;
                    ee=es;
                }
                else{
                    ee->next = curr;
                    ee = ee->next;
                }
            }
            i++;
        }
        if(es==NULL or os==NULL)
            return head;
        oe->next = es;
        ee->next=NULL;
        return os;
    }
};