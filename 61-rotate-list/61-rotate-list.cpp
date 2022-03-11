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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        vector<int>v;
        ListNode *curr = head;
        while(curr!=NULL){v.push_back(curr->val); curr = curr->next;}
        for(int i=0; i<k%v.size(); i++)
        {
            int temp = v[v.size()-1];
            for(int i=v.size()-1; i>=1; i--)
                v[i] = v[i-1];
            v[0] = temp;
        }
        curr = head;
        int j=0;
        while(curr!=NULL && j<v.size())
        {
            curr->val = v[j];
            curr = curr->next;
            j++;
        }
        return head;
    }
    
};