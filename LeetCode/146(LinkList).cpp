#include <iostream>
#include <unordered_map>

struct DLinkNode {
    int key, value;
    DLinkNode *pre, *nxt;
    DLinkNode(): key(0), value(0), pre(nullptr), nxt(nullptr) {}
    DLinkNode(int _key, int _value): key(_key), value(_value), pre(nullptr), nxt(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, DLinkNode*> cache;
    DLinkNode *head, *tail;
    int sz, capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), sz(0) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->nxt = tail;
        tail->pre = head; 
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkNode *node = cache[key];
        moveHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkNode *node = new DLinkNode(key, value);
            cache[key] = node;
            addHead(node);
            ++sz;
            if (sz > capacity) {
                DLinkNode *rem = removeTail();
                cache.erase(rem->key);
                delete rem;
                --sz;
            }
            return;
        }
        DLinkNode *node = cache[key];
        node->value = value;
        moveHead(node);
    }

    void addHead(DLinkNode *node) {
        node->pre = head;
        node->nxt = head->nxt;
        head->nxt->pre = node;
        head->nxt = node;
    }

    void removeNode(DLinkNode *node) {
        node->nxt->pre = node->pre;
        node->pre->nxt = node->nxt;
    }


    void moveHead(DLinkNode *node) {
        removeNode(node);
        addHead(node);
    }

    DLinkNode *removeTail() {
        DLinkNode *node = tail->pre;
        removeNode(node);
        return node;
    }
};

int main() {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);
    lRUCache->put(2, 2);
    std::cout << lRUCache->get(1) << std::endl;
    lRUCache->put(3, 3);
    std::cout << lRUCache->get(2) << std::endl;
    lRUCache->put(4, 4);
    std::cout << lRUCache->get(1) << std::endl;
    std::cout << lRUCache->get(3) << std::endl;
    std::cout << lRUCache->get(4) << std::endl;
    delete lRUCache;
    return 0;
}