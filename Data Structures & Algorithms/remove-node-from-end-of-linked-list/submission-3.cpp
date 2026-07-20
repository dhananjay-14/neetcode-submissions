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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        int len = 0;
        ListNode* hd = head;
        while(hd!=NULL){
            len++;
            hd = hd->next;
        }
        hd = head;
        int mid = len-n-1;
        if(mid==-1) return hd->next;

        while(mid){
            hd = hd->next;
            mid--;
        }

        ListNode* nn = hd->next ? hd->next->next : NULL;
        hd->next = nn;
        return head;
    }
};
