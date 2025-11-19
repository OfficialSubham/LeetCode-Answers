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

//     ListNode* halfReverse(ListNode* head, int cnt, int currentCnt) {
//         if(cnt == currentCnt || !head->next) return head;
//         ListNode* newHead = halfReverse(head->next, cnt, currentCnt+1);
//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     }

//     bool isPalindrome(ListNode* head) {
//         int cnt = 0;
//         ListNode* temp = head;
//         while(temp) {
//             cnt++;
//             temp = temp->next;
//         }

//         int counter = 1;
//         ListNode* secondHead = head;
//         int secondStop = (cnt / 2 + (cnt % 2 == 0 ? 0 : 1));
//         while(counter <= secondStop) {
//             secondHead = secondHead->next;
//             counter++;
//         }

//         int n = cnt/2;
//         ListNode* startHead = halfReverse(head, n, 1);

//         while(secondHead && startHead) {
//             if(secondHead->val != startHead->val) return false;
//             secondHead = secondHead->next;
//             startHead = startHead->next;
//         }
//         return true;
//     }

//     ListNode* reverseLL(ListNode* head) {
//         if(head->next == nullptr) return head;
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         ListNode* next;
//         while(curr) {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }

//     bool isPalindrome(ListNode* head) {
//     int cnt = 0;
//     ListNode* mover = head;
//     while(mover) {
//         cnt++;
//         mover = mover->next;
//     }

//     int mid = ((cnt + 1)/2);
//     ListNode* reversePointHead = nullptr;
//     mover = head;
//     cnt = 0;
//     while(mover) {
//         cnt++;
//         if(cnt == mid) {
//             reversePointHead = mover;
//             break;
//         }
//         mover = mover->next;
//     }
//     if(!reversePointHead) return false;

//     ListNode* reverseEnding = reverseLL(reversePointHead);
//     mover = head;
//     while(reverseEnding->next) {
//         if(reverseEnding->val != mover->val) return false;
//         mover = mover->next;
//         reverseEnding = reverseEnding->next;
//     }

//     return true;

//     }

    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mover = head;
        int len = 0;
        while(mover) {
            len++;
            mover = mover->next;
        }
        mover = head;
        int cnt = 0;
        int mid = (len + 1)/2;
        while(mover) {
            cnt++;
            if(cnt == mid) {
                break;
            }
            mover = mover->next;
        }
        ListNode* reverseHead = reverseLL(mover);
        ListNode* currHead = head;
        while(reverseHead && currHead) {
            if(reverseHead->val != currHead->val) return false;
            reverseHead = reverseHead->next;
            currHead = currHead->next;
        }
        return true;


    }
};