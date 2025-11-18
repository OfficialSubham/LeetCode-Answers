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
    // ListNode* middleNode(ListNode* head) {
    //     ListNode* temp = head;
    //     int cnt = 1;
    //     while(temp) {
    //         temp = temp->next;
    //         cnt++;
    //     }
    //     int mid = (cnt + 1)/2;
    //     int count = 1;
    //     ListNode* mover = head;
    //     while(mover) {
    //         if(count == mid) return mover;
    //         mover = mover->next;
    //         count++;
    //     }
    //     return NULL;
    // }

    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while(fastPtr) {
            if(fastPtr->next) fastPtr = fastPtr->next->next;
            else break;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};