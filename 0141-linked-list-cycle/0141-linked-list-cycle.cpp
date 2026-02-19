/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
        while(fastPtr) {
            if(fastPtr == slowPtr) return true;
            if(fastPtr->next) fastPtr = fastPtr->next->next;
            else break;
            slowPtr = slowPtr->next;
        }
        return false;
    }
};