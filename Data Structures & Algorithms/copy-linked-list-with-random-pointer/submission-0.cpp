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
        if(head==NULL) return NULL;
        Node* hd = head;
        unordered_map<Node*,Node*>dup;
        while(hd!=NULL){
            Node* nd = new Node(hd->val);
            dup[hd] = nd;
            hd = hd->next;
        }

        hd = head;
        while(hd!=NULL){
            if(hd->next==NULL) dup[hd]->next = NULL; 
            else dup[hd]->next = dup[hd->next];

            if(hd->random==NULL) dup[hd]->random = NULL; 
            else dup[hd]->random = dup[hd->random];

            hd = hd->next;
        }
        return dup[head];
    }
};
