class DLL {
    public:
        int value, key;
        DLL* prev;
        DLL* next;

    DLL(int v, int k): value(v), key(k), prev(nullptr), next(nullptr) {}

};

class LRUCache {
public:

    DLL* head;
    DLL* tail;
    int capacity;
    unordered_map<int, DLL*> hashMap;

    LRUCache(int c) {
        this->capacity = c;
        this->head = this->tail = nullptr;
    }

    void remove(DLL* node) {
        if(node->prev) {
            node->prev->next = node->next;
        }
        else this->head = node->next;

        if(node->next) {
            node->next->prev = node->prev;
        }
        else this->tail = node->prev;
    }

    void addToTail(DLL* node) {
        node->next = nullptr;
        if(this->tail) {
            node->prev = this->tail;
            this->tail->next = node;
        }        
        else {
            this->head = node;
        }
        this->tail = node;
    }
    
    int get(int key) {
        if(hashMap.count(key)) {
            DLL* node = hashMap[key];
            remove(node);
            addToTail(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hashMap.count(key)) {
            DLL* node = hashMap[key];
            node->value = value;
            remove(node);
            addToTail(node);
        }
        else {
            if(hashMap.size() == capacity) {
                DLL* old = head;
                remove(old);
                hashMap.erase(old->key);
                delete old;
            }
            DLL* node = new DLL(value, key);
            addToTail(node);
            hashMap[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */