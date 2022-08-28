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
        unordered_map<Node *, Node *>mp;
        Node *newHead = NULL , *trav = NULL, *curr = head;
        while(curr){
            Node *temp = new Node(curr->val);
            if(newHead==NULL){
                newHead = temp;
                trav = temp;
            }
            else{
                trav->next = temp;
                trav = trav->next;
            }
            mp[curr] = temp;
            curr = curr->next;
        }
        Node *fakeCurr=newHead;
        curr = head;
        while(curr){
            fakeCurr->random = mp[curr->random];
            curr = curr->next;
            fakeCurr = fakeCurr->next;
        }
        return newHead;
    }
};