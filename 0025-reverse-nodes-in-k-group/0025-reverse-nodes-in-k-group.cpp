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
/*
    pair<ListNode*, ListNode*> reverseLL(ListNode* head, int k) {
        ListNode* mover = head;
        int cnt = 0;
        bool isLongEnough = false;
        while(mover) {
            cnt++;
            if(cnt >= k) {
                isLongEnough = true;
                break;
            }
            mover = mover->next;
        }
        if(!isLongEnough) return {head, nullptr};
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while(k) {
            k--;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr;
        return {prev, head};

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* mover = head;
        ListNode* prevTail = nullptr;
        ListNode* newHead = nullptr;
        while(mover) {
            pair<ListNode*, ListNode*> revHeadAndTail = reverseLL(mover, k);
            if (revHeadAndTail.second == nullptr) {
                // leftover block
                prevTail->next = mover;  
                break;
            }
            if(!newHead) newHead  = revHeadAndTail.first;
            if(prevTail) prevTail->next = revHeadAndTail.first;
            prevTail = revHeadAndTail.second;
            if(prevTail)mover = prevTail->next;
        }

        return newHead;


    }
*/

    pair<ListNode*, ListNode*> reverseLL(ListNode* head, int k) {
        ListNode* mover = head;
        int len = 0;
        while(mover) {
            len++;
            if(len >= k) break;
            mover = mover->next;
        }
        if(len < k) return {head, nullptr};
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr && k--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = next;
        return {prev, head};
        
    }

    ListNode* reverseKGroup(ListNode* head, int k)  {
        if(!head || !head->next) return head;

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        ListNode* mover = head;
        while(mover) {
            auto [currHead, currTail] = reverseLL(mover, k);
            if(!newHead) newHead = currHead;
            if(tail) tail->next = currHead;
            tail = currTail;
            if(!currTail) break;
            mover = currTail->next; 
        }

        return newHead;

    }

};