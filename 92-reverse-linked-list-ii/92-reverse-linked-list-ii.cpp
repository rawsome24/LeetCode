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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode* curr= head;
        int len = 0;
        while(curr){
            len++;
            if(len>=left && len<=right)
                v.push_back(curr->val);
            curr=curr->next;
        }
        curr = head;
        len = 0;
        int j=0;
        reverse(v.begin(), v.end());
        while(curr){
            len++;
            if(len>=left && len<=right && j<v.size())
                curr->val = v[j], j++;
            curr = curr->next;
        }
        return head;
        
    }
};