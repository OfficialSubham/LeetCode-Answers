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
    // ListNode* deleteMiddle(ListNode* head) {
    //     int cnt = 0;
    //     ListNode* mover = head;
    //     while(mover) {
    //         cnt++;
    //         mover = mover->next;
    //     }

    //     if(cnt == 1) {
    //         return head->next;
    //     }
    //     else if(cnt == 2) {
    //         head->next = nullptr;
    //         return head;
    //     }

    //     int middle = cnt/2;
    //     int ptr = 0;
    //     mover = head;
    //     ListNode* temp = head;
    //     while(mover) {
    //         if(ptr == middle) {
    //             temp->next = mover->next;
    //             delete mover;
    //             return head;
    //         }
    //         ptr++;
    //         temp = mover;
    //         mover = mover->next;
    //     }

    //     return head;

    // }

    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;

        int len = 0;
        ListNode* mover = head;
        while(mover) {
            len++;
            mover = mover->next;
        }

        int middle = len/2;

        mover = head;

        while(middle--) {
            if(!middle) {
                ListNode* next = mover->next;
                mover->next = next->next;
                return head;
            }
            mover = mover->next;
        }
        return head;
    }

};