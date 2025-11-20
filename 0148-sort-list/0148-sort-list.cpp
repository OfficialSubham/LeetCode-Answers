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
    // ListNode* sortList(ListNode* head) {
    //     ListNode* temp = head;
    //     while(temp) {
    //         ListNode* mover = temp->next;
    //         while(mover) {
    //             if(mover->val < temp->val) {
    //                 int value = temp->val;
    //                 temp->val = mover->val;
    //                 mover->val = value;
    //             }
    //             mover = mover->next;
    //         }
    //         temp = temp->next;
    //     }
    //     return head;
    // }

    // ListNode* merge(ListNode* leftHead, ListNode* rightHead) {
    //     if(leftHead == NULL) return rightHead;
    //     if(rightHead == NULL) return leftHead;

    //     ListNode* temp = nullptr;
    //     ListNode* mover = nullptr;
    //     ListNode* lmover = leftHead;
    //     ListNode* rmover = rightHead;
    //     while(lmover && rmover) {
    //         if(lmover->val <= rmover->val) {
    //             if(temp == nullptr) {
    //                 temp = lmover;
    //                 mover = temp;
    //             }
    //             else {
    //                 mover->next = lmover;
    //                 mover = mover->next;
    //             }
    //             lmover = lmover->next;
    //         }
    //         else {
    //             if(temp == nullptr) {
    //                 temp = rmover;
    //                 mover = temp;
    //             }
    //             else {
    //                 mover->next = rmover;
    //                 mover = mover->next;
    //             }
    //             rmover = rmover->next;
    //         }

    //     }
    //     if(lmover) mover->next = lmover;
    //     if(rmover) mover->next = rmover;
    //     return temp;
    // }

    // //CleadCode
    // ListNode* merge(ListNode* leftHead, ListNode* rightHead) {
    //     if(!leftHead) return rightHead;
    //     if(!rightHead) return leftHead;

    //     //Initialize a dummy list;
    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;
    //     while (leftHead && rightHead) {
    //     if (leftHead->val <= rightHead->val) {
    //         tail->next = leftHead;
    //         leftHead = leftHead->next;
    //     } else {
    //         tail->next = rightHead;
    //         rightHead = rightHead->next;
    //     }
    //     tail = tail->next;
    // }

    // // Attach any remaining nodes
    // tail->next = (leftHead) ? leftHead : rightHead;

    //     return dummy.next;
    // }

    // ListNode* sortList(ListNode* head) {
    //     if(!head || !head->next) return head;
    //     ListNode* prev = nullptr;
    //     ListNode* slowPtr = head;
    //     ListNode* fastPtr = head;
    //     while(fastPtr && fastPtr->next) {
    //         prev = slowPtr;
    //         fastPtr = fastPtr->next->next;
    //         slowPtr = slowPtr->next;
    //     }
    //     prev->next = nullptr;
    //     ListNode* leftHead = head;
    //     ListNode* rightHead = slowPtr;
    //     ListNode* left = sortList(leftHead);
    //     ListNode* right = sortList(rightHead);

    //     return merge(left, right);

    // }

    ListNode* mergeList(ListNode* leftHead, ListNode* rightHead) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(leftHead && rightHead) {
            if(leftHead->val <= rightHead->val) {
                tail->next = leftHead;
                leftHead = leftHead->next;
            }
            else {
                tail->next = rightHead;
                rightHead = rightHead->next;
            }
            tail = tail->next;
        }
        if(leftHead) tail->next = leftHead;;
        if(rightHead) tail->next = rightHead;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            if(!fast) break;
            slow = slow->next;
        }
        ListNode* left = head;
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* rightHead = sortList(mid);
        ListNode* leftHead = sortList(head);
        return mergeList(leftHead, rightHead);
    }



};