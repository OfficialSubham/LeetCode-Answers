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

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int leng = 0;
        ListNode* mover = head;
        while(mover) {
            leng++;
            mover = mover->next;
        }
        k %= leng;
        if(k == 0) return head;
        
        int iteration = leng - k - 1;
        mover = head;

        while(mover && iteration--) mover = mover->next;

        ListNode* newHead = mover->next;
        mover->next = nullptr;

        ListNode* tail = newHead;

        while(tail->next) tail = tail->next;

        if(tail != newHead) tail->next = head;
        else newHead->next = head;

        return newHead;
    }
};