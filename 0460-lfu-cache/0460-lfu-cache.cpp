class DLL {
    public:
    int key, value, freq;
    DLL* next;
    DLL* prev;
    DLL(int k, int v): key(k), value(v), freq(1), next(nullptr), prev(nullptr) {};
};

class List {
    public:
    DLL* head;
    DLL* tail;
    int size;
    List() {
        this->head = new DLL(0, 0);
        this->tail = new DLL(0, 0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->size = 0;
    }

    void remove(DLL* node) {
        DLL* delPrev = node->prev;
        DLL* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;  
        this->size--;      
    }

    void addNode(DLL* node) {
        DLL* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        this->size++;
    }

};

class LFUCache {
public:

    int capacity, miniFreq, currSize;
    unordered_map<int, DLL*> keyNodeHashMap;
    unordered_map<int, List*> freqHashMap; 

    LFUCache(int c) {
        this->capacity = c;
        this->miniFreq = 1;
        this->currSize = 0;
    }
    
    void updateFreqMap(DLL* node) {
        keyNodeHashMap.erase(node->key);
        freqHashMap[node->freq]->remove(node);

        if(this->miniFreq == node->freq && freqHashMap[node->freq]->size == 0) {
            this->miniFreq++;
        }
        List* freqList;
        if(freqHashMap.count(node->freq+1)) freqList = freqHashMap[node->freq + 1];
        else freqList = new List();

        node->freq += 1;
        freqList->addNode(node);
        freqHashMap[node->freq] = freqList;
        keyNodeHashMap[node->key] = node;
    }

    int get(int key) {
        if(!keyNodeHashMap.count(key)) return -1;
        DLL* node = keyNodeHashMap[key];
        int value = node->value;
        updateFreqMap(node);
        return value;
    }
    
    void put(int key, int value) {
        if(this->capacity == 0) return;
        if(keyNodeHashMap.count(key)) {
            DLL* node = keyNodeHashMap[key];
            node->value = value;
            updateFreqMap(node);
            return;
        }

        if(this->capacity == this->currSize) {
            List* freqList = freqHashMap[miniFreq];
            keyNodeHashMap.erase(freqList->tail->prev->key);
            DLL* node = freqList->tail->prev;
            freqList->remove(node);
            this->currSize--;
        }
        this->currSize++;

        DLL* node = new DLL(key, value);
        this->miniFreq = 1;

        List* freqList;
        if(freqHashMap.count(miniFreq)) freqList = freqHashMap[miniFreq];
        else freqList = new List();

        freqList->addNode(node);
        freqHashMap[miniFreq] = freqList;
        keyNodeHashMap[key] = node;
    }
};