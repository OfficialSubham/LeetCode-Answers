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
    // ListNode* oddEvenList(ListNode* head) {
        
    //     int cnt = 0;
    //     ListNode* mover = head;
    //     //Handling Edge case
    //     while(mover){
    //         cnt++;
    //         if(cnt > 2) break;
    //         mover = mover->next;
    //     }

    //     if(cnt <= 2) return head;

    //     ListNode* oddHead = head;
    //     ListNode* evenHead = head->next;

    //     ListNode* odd = oddHead;
    //     ListNode* even = evenHead;

    //     while(odd->next != nullptr && even->next != nullptr) {
    //         odd->next = even->next;
    //         odd = odd->next;
    //         even->next = odd->next;
    //         even = even->next;
    //     }

    //     odd->next = evenHead;

    //     return head;
    // }

    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* oddNode = head;
        ListNode* evenNode = head->next;

        ListNode* oddTail = oddNode;
        ListNode* evenTail = evenNode;
        
        while(oddTail->next && evenTail->next) {
            oddTail->next = evenTail->next;
            oddTail = oddTail->next;
            evenTail->next = oddTail->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenNode;
        return oddNode;

    }

};