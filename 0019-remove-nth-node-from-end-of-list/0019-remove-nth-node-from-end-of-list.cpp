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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int cnt  = 0;
    //     ListNode* mover = head;
    //     while(mover) {
    //         cnt++;
    //         mover = mover->next;
    //     }
    //     if(cnt == n) return head->next;

    //     int nthNode = (cnt - n) + 1;

    //     int looping = 0;
    //     mover = head;
    //     ListNode* temp = head;
    //     while(mover) {
    //         looping++;
    //         if(looping == nthNode) {
    //             temp->next = mover->next;
    //             delete mover;
    //             return head;
    //         }
    //         temp = mover;
    //         mover = mover->next;
    //     }

    //     return head;
    // }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n == 0) return head;
        int len = 0;
        ListNode* mover = head;
        while(mover) {
            len++;
            mover = mover->next;
        }

        if(n > len) return head;
        if(n == len) {
            ListNode* newHead = head->next;
            return newHead;
        }

        mover = head;
        int nthNode = len - n;
        int cnt = 0;
        while(mover) {
            cnt++;
            if(nthNode == cnt) {
                ListNode*  next = mover->next;
                mover->next = next->next;
                return head;
            }
            mover = mover->next;
        }
        return head;
    }

};