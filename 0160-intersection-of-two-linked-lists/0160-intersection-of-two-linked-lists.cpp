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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* moverA = headA;
    //     while(moverA) {
    //         ListNode* moverB = headB;
    //         while(moverB) {
    //             if(moverB == moverA) return moverA;
    //             moverB = moverB->next;
    //         }
    //         moverA = moverA->next;
    //     }
    //     return NULL;
    // }
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0;
        int cntB = 0;
        ListNode* moverA = headA;
        ListNode* moverB = headB;

        while(moverA) {
            cntA++;
            moverA = moverA->next;
        }

        while(moverB) {
            cntB++;
            moverB = moverB->next;
        }

        int diff = abs(cntA - cntB);

        moverA = headA;
        moverB = headB;
        if(cntA > cntB) {
            while(moverA && diff > 0) {
                diff--;
                moverA = moverA->next;
            }
        }
        else {
            while(moverB && diff > 0) {
                diff--;
                moverB = moverB->next;
            }
        }

        while(moverA && moverB) {
            if(moverA == moverB) return moverA;
            moverA = moverA->next;
            moverB = moverB->next;
        }

        return NULL;

    }
    */

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)  {
        int cntA = 0;
        int cntB = 0;

        ListNode* moverA = headA;
        ListNode* moverB = headB;

        while(moverA) {
            cntA++;
            moverA = moverA->next;
        }

        while(moverB) {
            cntB++;
            moverB = moverB->next;
        }

        int diff = abs(cntA - cntB);
        moverA = headA;
        moverB = headB;
        if(cntA > cntB) {
            while(diff--) {
                moverA = moverA->next;
            }
        }
        else {
            while(diff--) {
                moverB = moverB->next;
            }
        }

        while(moverA && moverB && moverA != moverB) {
            moverA = moverA->next;
            moverB = moverB->next;
        }
        return moverA;
    }

};