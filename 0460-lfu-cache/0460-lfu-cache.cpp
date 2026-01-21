class Node {
    public:
    int key, value, cnt;
    Node* next;
    Node* prev;

    Node(int k, int v): key(k), value(v), cnt(1), next(nullptr), prev(nullptr) {}
};

class List {
    public:
    int size;
    Node* head;
    Node* tail;
    
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

};


class LFUCache {
public:

    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int capacity;
    int minFreq;
    int currSize;
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->remove(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherListFreq = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherListFreq = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherListFreq->addFront(node);
        freqListMap[node->cnt] = nextHigherListFreq;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else {
            if(currSize == capacity) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->remove(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */