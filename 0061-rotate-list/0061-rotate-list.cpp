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
        if(!head || !head->next || k == 0) return head;

        int len = 0;
        ListNode* mover = head;
        ListNode* tail = nullptr;
        while(mover) {
            len++;
            if(!mover->next) tail = mover;
            mover = mover->next;
        }
        k %= len;
        if(k == 0) return head;
        //Made a circle linkedList
        tail->next = head;

        mover = head;
        int cut = len - k;
        while(cut--) {
            if(cut == 0) {
                head = mover->next;
                mover->next = nullptr;
                break;
            }
            mover = mover->next;
        }
        return head;
    }

};
