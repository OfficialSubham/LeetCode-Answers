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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode* mover = head;
        ListNode* fastPtr = head;

        while(fastPtr) {
            if(!fastPtr->next) return nullptr;
            mover = mover->next;
            fastPtr = fastPtr->next->next;
            if(mover == fastPtr) break;
        }

        ListNode* start = head;

        while(fastPtr) {
            if(start == fastPtr) return start;
            start = start->next;
            fastPtr = fastPtr->next;
        }

        return nullptr;
    }
};