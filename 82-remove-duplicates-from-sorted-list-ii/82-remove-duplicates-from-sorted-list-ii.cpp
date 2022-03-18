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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        map<int,int>mp;
        ListNode *curr=head;
        while(curr!=NULL){mp[curr->val]++; curr=curr->next;}
        head = NULL;
        bool h = true;
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            if(it->second==1)
            {
                if(h)
                {
                    head = new ListNode(it->first); 
                    curr = head; 
                    h=false;
                }
                else
                {
                    ListNode *temp = new ListNode(it->first);
                    curr->next = temp;
                    curr = curr->next;
                }
            }
        }
        
        return head;
    }
};