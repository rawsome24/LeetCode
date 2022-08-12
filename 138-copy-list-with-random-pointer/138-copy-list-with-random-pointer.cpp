/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node *ans = new Node (-1);
        Node *trav = ans;
        Node *curr = head;
        while(curr){
            if(mp.find(curr)==mp.end()){
                Node *tmp = new Node (curr->val);
                mp[curr] = tmp;
            }
            trav->next = mp[curr];
            trav = trav->next;
            
            if(curr->random!=NULL){
                if(mp.find(curr->random)==mp.end()){
                    Node *temp = new Node(curr->random->val);
                    mp[curr->random] = temp;
                }
                trav->random = mp[curr->random];
            }
            curr = curr->next;
        }
        return ans->next;
    }
};