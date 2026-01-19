class DLL {
    public:
    int key, value;
    DLL* next;
    DLL* prev;

    DLL(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {} 
};


class LRUCache {
private:
    DLL* head;
    DLL* mover;
    unordered_map<int, DLL*> hashMap;
    int capacity;

    void remove(DLL* node) {
        if(node->prev) {
            node->prev->next = node->next;
        }
        else this->head = node->next;

        if(node->next) {
            node->next->prev = node->prev;
        }
        else this->mover = node->prev;
    }

    void addItToTail(DLL* node) {
        node->next = nullptr;
        if(this->mover) { 
            node->prev = this->mover;
            this->mover->next = node;
        }
        else {
            this->head = node;
        }
        this->mover = node;
    }

public:
    LRUCache(int cap) {
        this->capacity = cap;
        this->head = this->mover = nullptr;
    }
    
    int get(int key) {
        if(hashMap.count(key)) {
            int value = hashMap[key]->value;
            remove(hashMap[key]);
            addItToTail(hashMap[key]);
            return value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(hashMap.count(key)) {
            hashMap[key]->value = value;
            remove(hashMap[key]);
            addItToTail(hashMap[key]);
        }
        else {
            if(hashMap.size() == this->capacity) {
                DLL* old = head;
                remove(head);
                hashMap.erase(old->key);
                delete old;
            }
            DLL* newPair = new DLL(key, value);
            addItToTail(newPair);
            hashMap[key] = newPair;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */