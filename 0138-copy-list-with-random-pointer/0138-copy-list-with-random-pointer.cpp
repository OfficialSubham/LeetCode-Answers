/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    int getIndexOfNode(Node* head, Node* random) {
        int cnt = 0;
        while(head) {
            cnt++;
            if(head == random) return cnt;
            head = head->next;
        } 
        return cnt;
    }
    
    Node* getNodeAtIndex(Node* head, int n) {
        int cnt = 0;
        while(head) {
            cnt++;
            if(cnt == n) return head;
            head = head->next;
        }
        return nullptr;
    }

    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* copiedHead = new Node(head->val);
        Node* mover = head->next;
        Node* tail = copiedHead;

        while(mover) {
            Node* tempNode = new Node(mover->val);
            tail->next = tempNode;
            tail = tail->next;
            mover = mover->next;
        }
        mover = head;
        Node* copiedMover = copiedHead;
        while(mover) {
            if(mover->random) {
                int nthNode = getIndexOfNode(head, mover->random);
                Node* randomNode = getNodeAtIndex(copiedHead, nthNode);
                copiedMover->random = randomNode;
            }
            mover = mover->next;
            copiedMover = copiedMover->next;
        }

        return copiedHead;
    }
};