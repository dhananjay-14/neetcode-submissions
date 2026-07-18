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
    ListNode* reverse(ListNode* nd){
        if(nd==NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = nd;
        ListNode* next = nd->next;

        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* st = head;
        int len = 0;
        while(st!=NULL){
            len++;
            st = st->next;
        }
        int ind = len/2 -1 ;
        st = head;
        while(ind>0){
            st = st->next;
            ind--;
        }

        ListNode* curr = st;
        ListNode* nxt = st->next;
        curr->next = NULL;

        st = head;
      

        ListNode* lst = reverse(nxt);

        // st and lst

        while(st!=NULL && lst!=NULL){
            curr = st;
            st = st->next;
            curr->next = lst;
            curr = lst;
            lst = lst->next;
            curr->next = st;
        }
        if(len%2!=0) curr->next = lst;
    }
};
