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
/*
    // int getIndexOfNode(Node* head, Node* random) {
    //     int cnt = 0;
    //     while(head) {
    //         cnt++;
    //         if(head == random) return cnt;
    //         head = head->next;
    //     } 
    //     return cnt;
    // }
    
    // Node* getNodeAtIndex(Node* head, int n) {
    //     int cnt = 0;
    //     while(head) {
    //         cnt++;
    //         if(cnt == n) return head;
    //         head = head->next;
    //     }
    //     return nullptr;
    // }

    // Node* copyRandomList(Node* head) {
    //     if(!head) return head;
    //     Node* copiedHead = new Node(head->val);
    //     Node* mover = head->next;
    //     Node* tail = copiedHead;

    //     while(mover) {
    //         Node* tempNode = new Node(mover->val);
    //         tail->next = tempNode;
    //         tail = tail->next;
    //         mover = mover->next;
    //     }
    //     mover = head;
    //     Node* copiedMover = copiedHead;
    //     while(mover) {
    //         if(mover->random) {
    //             int nthNode = getIndexOfNode(head, mover->random);
    //             Node* randomNode = getNodeAtIndex(copiedHead, nthNode);
    //             copiedMover->random = randomNode;
    //         }
    //         mover = mover->next;
    //         copiedMover = copiedMover->next;
    //     }

    //     return copiedHead;
    // }

    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* original = head;
        while(original){
            Node* tempNode = new Node(original->val);
            Node* next = original->next;
            original->next = tempNode;
            original = next;
            tempNode->next = original;
        }

        original = head;

        Node* curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random ? curr->random->next : nullptr;
            }
            curr = curr->next->next;
        }

        Node* currHead = head;
        Node* cloneHead = head->next;

        while(currHead) {
            Node* clone = currHead->next;
            currHead->next = clone->next;
            if(clone->next) clone->next = clone->next->next;
            currHead = currHead->next;
        }

        return cloneHead;

        
    }

*/

    Node* copyRandomList(Node* head)  {
        if(!head) return nullptr;

        Node* mover = head;

        while(mover) {
            Node* next = mover->next; 
            Node* copied = new Node(mover->val);
            mover->next = copied;
            copied->next = next;
            mover = next;
        }

        mover = head;

        while(mover) {
            if(mover->random) {
                mover->next->random = mover->random->next;
            }
            mover = mover->next->next;
        }

        Node* original = head;
        Node* copiedHead = head->next;

        while(original) {
            Node* clone = original->next;
            original->next = clone->next;
            if(clone->next)clone->next = clone->next->next;
            original = original->next; 
        }

        return copiedHead;

    }

};