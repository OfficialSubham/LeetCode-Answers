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
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* leftHead = sortList(head);
        ListNode* rightHead = sortList(slow);
        return mergeList(leftHead, rightHead);
    }



};