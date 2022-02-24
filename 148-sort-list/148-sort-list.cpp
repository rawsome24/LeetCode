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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode *curr = head;
        while(curr){v.push_back(curr->val); curr=curr->next;}
        sort(v.begin(),v.end());
        curr = head;
        for(auto x:v)
        {
            if(curr==NULL)break;
            curr->val = x;
            curr=curr->next;
        }
        return head;
    }
};