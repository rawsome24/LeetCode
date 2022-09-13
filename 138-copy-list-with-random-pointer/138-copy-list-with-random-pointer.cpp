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
        Node *curr = head, *trav=NULL;
        Node *newHead = NULL;
        while(curr){
            Node *temp = new Node (curr->val);
            if(newHead==NULL){
                newHead = temp;
                trav = newHead;
            }
            else{
                trav->next = temp;
                trav = trav->next;
            }
            mp[curr] = temp;
            curr = curr->next;
        }
        curr = newHead;
        Node *temp = head;
        while(curr){
            curr->random = mp[temp->random];
            curr = curr->next;
            temp = temp->next;
        }
        return newHead;
    }
};