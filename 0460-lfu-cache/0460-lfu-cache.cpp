class DLL {
    public:
    int value, freq, key;
    DLL* next;
    DLL* prev;

    DLL(int v, int k):  value(v), freq(1), key(k), next(nullptr), prev(nullptr) {};
};

class LRUCache {
    public:
    int size;
    DLL* head;
    DLL* tail;
    
    LRUCache() {
        this->head = new DLL(0, 0);
        this->tail = new DLL(0, 0);
        this->head->next = tail;
        this->tail->prev = head;
        size = 0;
    }

    void addToTail(DLL* node) {
        DLL* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        this->size++;
    }

     void removeNode(DLL* node) {
        DLL* delPrev = node->prev;
        DLL* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        this->size--;
    }
};

class LFUCache {
public:
    int miniFreq, capacity, currSize;
    unordered_map<int, DLL*> keyNodeMap;
    unordered_map<int, LRUCache*> freqListMap;

    void updateFreqList(DLL* node) {
        keyNodeMap.erase(node->key);
        freqListMap[node->freq]->removeNode(node);

        if(node->freq == this->miniFreq && freqListMap[node->freq]->size == 0) {
            this->miniFreq++;
        }

        LRUCache* nextHigherFreq = new LRUCache();
        if(freqListMap.count(node->freq + 1)) {
            nextHigherFreq = freqListMap[node->freq+1];
        }

        node->freq += 1;
        nextHigherFreq->addToTail(node); 
        freqListMap[node->freq] = nextHigherFreq;
        keyNodeMap[node->key] = node;
    }


    LFUCache(int c) {
        miniFreq = 0;
        currSize = 0;
        capacity = c;
    }
    


    int get(int key) {
        if(keyNodeMap.count(key)) {
            DLL* node = keyNodeMap[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(keyNodeMap.count(key)) {
            DLL* node = keyNodeMap[key];
            node->value = value;
            updateFreqList(node);
        }
        else {
            if(currSize == capacity) {
                LRUCache* list = freqListMap[this->miniFreq];
                keyNodeMap.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            this->miniFreq = 1;
            DLL* node = new DLL(value, key);
            LRUCache* list = new LRUCache();
            if(freqListMap.count(this->miniFreq)) {
                list = freqListMap[this->miniFreq];
            }
            list->addToTail(node);
            keyNodeMap[key] = node;
            freqListMap[this->miniFreq] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */