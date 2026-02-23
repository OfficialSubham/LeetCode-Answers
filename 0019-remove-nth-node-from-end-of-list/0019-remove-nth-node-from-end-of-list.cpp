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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* mover = head;
        while(mover) {
            len++;
            mover = mover->next;
        }

        if(n > len) return head;
        if(n == len) return head->next;

        int nodeToRemove = len - n;
        mover = head;
        while(mover) {
            nodeToRemove--;
            if(nodeToRemove == 0) {
                ListNode* temp = mover->next;
                if(temp) mover->next = temp->next;
                return head; 
            }
            mover = mover->next;
        }
        return head;
    }
};