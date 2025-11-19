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
    //19/11/25
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        ListNode* start = head;
        bool isLoop = false;
        while(fastNode && fastNode->next) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
            if(slowNode == fastNode) {
                isLoop = true;
                break;               
            } 
        }
        if(!isLoop) return nullptr;

        while(start != fastNode) {
            if(fastNode == start) return start;
            fastNode = fastNode->next;
            start = start->next;
        }
        return start;

    }

};