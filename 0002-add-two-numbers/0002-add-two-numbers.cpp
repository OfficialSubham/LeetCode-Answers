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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0;
        int len2 = 0;

        ListNode* m1 = l1;
        ListNode* m2 = l2;

        while(m1) {
            len1++;
            m1 = m1->next;
        }

        while(m2) {
            len2++;
            m2 = m2->next;
        }
        int carry = 0;
    
        m1 = l1;
        m2 = l2;
    
        if(len1 <= len2) {
            while(m1) {
                int sum = m1->val + m2->val + carry;
                carry = sum/10;
                m2->val = sum%10;
                m1 = m1->next;
                m2 = m2->next;
            }
            while(m2 && carry) {
                int sum = m2->val + carry;
                carry = sum /10;
                m2->val = sum % 10;
                m2 = m2->next;
            }
        }
        else {
            while(m2) {
                int sum = m1->val + m2->val + carry;
                carry = sum/10;
                m1->val = sum%10;
                m1 = m1->next;
                m2 = m2->next;
            }
            while(m1 && carry) {
                int sum = m1->val + carry;
                carry = sum /10;
                m1->val = sum % 10;
                m1 = m1->next;
            }
        }

        if(carry) {
            ListNode* temp = new ListNode(carry);
            ListNode* mover;
            if(len1 <= len2) mover = l2;
            else mover = l1;
            while(mover->next) mover = mover->next;
            mover->next = temp;
        }
        if(len1 <= len2) return l2;
        return l1;
    }
};