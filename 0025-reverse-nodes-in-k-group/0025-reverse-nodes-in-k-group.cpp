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

    pair<ListNode*, ListNode*> reverseLL(ListNode* head, int k) {
        if(!head || !head->next) return {head, nullptr};
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr && k--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr;
        return {prev, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0) return head;
        ListNode* mover = head;
        int count = 0;
        while(mover) {
            count++;
            mover = mover->next;
        }
        
        int iteration = count/k;
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        mover = head;
        while(count >= k && iteration--) {
            count -= k;
            auto [currHead, next] = reverseLL(mover, k);
            if(!newHead) {
                newHead = currHead;
                tail = next;
            }
            else {
                tail->next = currHead;
                tail = next;
            }
            if(next) mover = next->next;
            else mover = nullptr;
        }
        return newHead;

    }
};