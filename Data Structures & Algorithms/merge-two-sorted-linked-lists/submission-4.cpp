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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        int lead = 0;
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val<=list2->val){
            head = list1;
        }else{
            head = list2;
        }

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1!=NULL && p2!=NULL){
            int val1 = p1->val; int val2 = p2->val;
            if(val1<=val2){
                if(lead == 0 && p1->next!=NULL && p1->next->val<=val2){
                    p1 = p1->next;
                }else if(lead==0){
                    ListNode* curr = p1;
                    p1 = p1->next;
                    curr->next = p2;
                    lead = 1;
                }else{
                    if(p2->next!=NULL && p2->next->val<=val1){
                        p2 = p2->next;
                    }else{
                    ListNode* curr = p2;
                    p2 = p2->next;
                    curr->next = p1;
                    lead = 0;
                    }
                }
            }else{
               if(p2->next!=NULL && p2->next->val<=val1){
                  p2 = p2->next;
               }else{
                  ListNode* curr = p2;
                  p2 = p2->next;
                  curr->next = p1;
                  lead = 0;
               }
            }
        }
        return head;
    }
};
