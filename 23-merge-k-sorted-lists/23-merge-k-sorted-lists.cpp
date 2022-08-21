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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()==0)
        //     return NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode *head = NULL;
        ListNode *trav = NULL;
        while(!pq.empty()){
            if(head==NULL){
                auto node = pq.top().second;
                int value = pq.top().first;
                ListNode *temp = new ListNode (value);
                pq.pop();
                if(node->next)
                    pq.push({node->next->val, node->next});
                head =  temp;
                trav = temp;
            }
            else{
                auto node = pq.top().second;
                int value = pq.top().first;
                ListNode *temp = new ListNode (value);
                pq.pop();
                if(node->next)
                    pq.push({node->next->val, node->next});
                trav->next = temp;
                trav = trav->next;
            }
        }
        return head;
    }
};