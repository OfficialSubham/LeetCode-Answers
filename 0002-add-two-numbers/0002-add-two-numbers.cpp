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

/*

    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int sum = 0;
    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;

    //     ListNode* mover1 = l1; 
    //     ListNode* mover2 = l2;

    //     while(mover1 && mover2) {
    //         sum += mover1->val + mover2->val;
    //         if(sum >= 10) {
    //             int rem = sum%10;
    //             ListNode* temp = new ListNode(rem);
    //             tail->next = temp;
    //             tail = tail->next;
    //             sum /= 10;
    //         }
    //         else {
    //             ListNode* temp = new ListNode(sum);
    //             tail->next = temp;
    //             tail = tail->next;
    //             sum /= 10;
    //         }
    //         mover1 = mover1->next;
    //         mover2 = mover2->next;
    //     }

    //     if(mover1) {
    //         while(sum > 0) {
    //             if(mover1) sum += mover1->val;
    //             if(sum >= 10) {
    //                 int rem = sum%10;
    //                 ListNode* temp = new ListNode(rem);
    //                 tail->next = temp;
    //                 tail = tail->next;
    //                 sum /= 10;
    //             }
    //             else {
    //                 ListNode* temp = new ListNode(sum);
    //                 tail->next = temp;
    //                 tail = tail->next;
    //                 sum /= 10;
    //             }
    //             if(mover1) mover1 = mover1->next;
    //         }
    //         tail->next = mover1;
    //     }
    //     else if(mover2) {
    //         while(sum > 0) {
    //             if(mover2) sum += mover2->val;
    //             if(sum >= 10) {
    //                 int rem = sum%10;
    //                 ListNode* temp = new ListNode(rem);
    //                 tail->next = temp;
    //                 tail = tail->next;
    //                 sum /= 10;
    //             }
    //             else {
    //                 ListNode* temp = new ListNode(sum);
    //                 tail->next = temp;
    //                 tail = tail->next;
    //                 sum /= 10;
    //             }
    //             if(mover2) mover2 = mover2->next;
    //         }
    //         tail->next = mover2;
    //     }
    //     else if(sum > 0) {
    //          while(sum > 0) {
    //             if(sum >= 10) {
    //                 int rem = sum%10;
    //                 ListNode* temp = new ListNode(rem);
    //                 tail->next = temp;
    //                 tail = tail->next;
    //                 sum /= 10;
    //             }
    //             else {
    //                 ListNode* temp = new ListNode(sum);
    //                 tail->next = temp;
    //                 tail = tail->next;
    //                 sum /= 10;
    //             }
    //         }
    //     }
    //     return dummy.next;
    // }

    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int sum = 0;
    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;
    //     ListNode* mover1 = l1;
    //     ListNode* mover2 = l2;
    //     while(mover1 || mover2 || sum > 0) {
    //         if(mover1) sum += mover1->val;
    //         if(mover2) sum += mover2->val;
    //         int value = sum % 10;
    //         ListNode* temp = new ListNode(value);
    //         tail->next = temp;
    //         tail = temp;
    //         sum /= 10;
    //         if(mover1) mover1 = mover1->next;
    //         if(mover2) mover2 = mover2->next;
    //     }
    //     return dummy.next;
    // }

*/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* mover1 = l1;
        ListNode* mover2 = l2;
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(mover1 && mover2) {
            int sum = (mover1->val + mover2->val + carry);
            mover1->val = (sum % 10);
            carry = sum / 10;
            tail->next = mover1;
            tail = tail->next;
            mover1 = mover1->next;
            mover2 = mover2->next;
        }
        while(mover1) {
            int sum = mover1->val + carry;
            mover1->val = sum % 10;
            carry = sum /10;
            tail->next = mover1;
            tail = tail->next;
            mover1 = mover1->next;
        }

        while(mover2) {
            int sum = mover2->val + carry;
            mover2->val = sum % 10;
            carry = sum /10;
            tail->next = mover2;
            tail = tail->next;
            mover2 = mover2->next;    
        }
        if(carry) {
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
        }
        return dummy.next;
    } 

};