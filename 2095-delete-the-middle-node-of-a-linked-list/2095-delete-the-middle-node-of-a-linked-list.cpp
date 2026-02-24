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
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* mover = head;

        while(mover) {
            len++;
            mover = mover->next;
        }

        int middle = len/2;
        mover = head;
        while(mover && middle--) {
            if(!middle) {
                ListNode* temp = mover->next;
                if(temp) mover->next = temp->next;
                break;
            }
            mover = mover->next;
        }
        return head;

    }
};