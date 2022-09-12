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
        ListNode *os = NULL, *oe = NULL, *es = NULL, *ee = NULL;
        ListNode *curr = head;
        int i = 0;
        while(curr){
            ListNode *temp = new ListNode (curr->val);
            if(i%2==0){
                if(es==NULL){
                    es = temp;
                    ee = es;
                }
                else{
                    ee->next = temp;
                    ee = ee->next;
                }
            }
            else{
                if(os == NULL){
                    os = temp;
                    oe = os;
                }
                else{
                    oe->next = temp;
                    oe = oe->next;
                }
            }
            i++;
            curr = curr->next;
        }
        if(os==NULL or es==NULL)
            return head;
        ee->next = os;
        return es;
    }
};