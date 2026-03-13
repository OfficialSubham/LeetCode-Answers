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
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* mover = head;
        while(mover) {
            Node* dupliNode = new Node(mover->val);
            Node* tempNode = mover->next;
            mover->next = dupliNode;
            dupliNode->next = tempNode;
            mover = tempNode;
        }

        mover = head;
        while(mover) {
            if(mover->random) {
                mover->next->random = mover->random->next;
            }
            mover = mover->next->next;
        }
        
        Node* actualNode = head;
        Node* ansNode = head->next;

        Node* actualNodeTail = actualNode;
        Node* ansNodeTail = ansNode;

        while(actualNodeTail) {
            actualNodeTail->next = ansNodeTail->next;
            actualNodeTail = actualNodeTail->next;
            if(actualNodeTail) ansNodeTail->next = actualNodeTail->next;
            else ansNodeTail->next = nullptr;
            ansNodeTail = ansNodeTail->next;
        }

        return ansNode;
       

    }
};