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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL) return false;
        while(true){
            slow = slow->next;
            if(fast->next)fast = fast->next->next;
            if(fast==slow) return true;
            else if(fast==NULL || fast->next==NULL) return false;
        }

        return true;
    }
};
