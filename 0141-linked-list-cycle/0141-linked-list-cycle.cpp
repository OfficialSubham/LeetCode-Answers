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
    // bool hasCycle(ListNode *head) {
        
    //     ListNode* temp = head;
    //     ListNode* mover = head;
    //     while(temp) {
    //         if(temp->next == nullptr) return false;
    //         if(temp->next == mover) return true;
    //         mover = mover->next;
    //         temp = temp->next->next;
    //     }
    //     return false;
    // }

    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* fastPtr = head->next->next;
        ListNode* slowPtr = head;
        while(fastPtr) {
            if(slowPtr == fastPtr) return true;
            slowPtr = slowPtr->next;
            if(fastPtr->next) fastPtr = fastPtr->next->next;
            else break;
        }
        return false;
    }

};