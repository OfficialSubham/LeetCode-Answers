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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = new ListNode(0);
        ListNode* oddMover = odd;
        ListNode* even = new ListNode(0);
        ListNode* evenMover = even;

        bool takeOdd = true;

        while(head) {
            ListNode* nextPtr = head->next;
            if(takeOdd) {
                oddMover->next = head;
                oddMover = head;
                oddMover->next = nullptr;
            }
            else {
                evenMover->next = head;
                evenMover = head;
                evenMover->next = nullptr;
            }

            head = nextPtr;
            takeOdd = !takeOdd;
        }

        oddMover->next = even->next;
        return odd->next;
    }
};