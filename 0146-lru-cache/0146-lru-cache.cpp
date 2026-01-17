#include<bits/stdc++.h>

class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
    Node(int key1, int value1) {
        key = key1;
        value = value1;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* mover;
    
    void remove(Node* node) {
        if(node->prev) node->prev->next = node->next;
        else this->head = node->next;

        if(node->next) node->next->prev = node->prev;
        else this->mover = node->prev;
    }

    void addToTail(Node* node) {
        node->prev = this->mover;
        node->next = nullptr;

        if(this->mover) this->mover->next = node;
        else head = node;
        this->mover = node;
    }


public:

    LRUCache(int cap) {
        this->capacity = cap;
        this->head = this->mover = nullptr;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;

        Node* node = cache[key];
        remove(node);
        addToTail(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            addToTail(node);
        }
        else {
            if(cache.size() == this->capacity) {
                Node* old = head;
                cache.erase(old->key);
                remove(old);
                delete old;
            }
            Node* node = new Node(key, value);
            addToTail(node);
            cache[key] = node;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */