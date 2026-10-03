struct Node {
    Node* next;
    Node* prev;
    int val;
    int key;
    Node() : val(0), next(nullptr) {}
    Node(int k, int v) : key(k), val(v), next(nullptr) {}
};


class LRUCache {
public:
    unordered_map<int, Node*> stored;
    Node* dummy;
    Node* dummy2;
    int size = 0;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        dummy = new Node();
        dummy2 = new Node();
        dummy->next = dummy2;
        dummy2 -> prev = dummy;
    }
    
    int get(int key) {
        if(stored.find(key) == stored.end()){
            return -1;
        }
        remove(stored[key]);
        insert(stored[key]);
        return stored[key]->val;
    }
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        node->prev = dummy2->prev;
        dummy2->prev->next = node;
        dummy2->prev = node;
        node->next = dummy2;
    }
    void put(int key, int value) {
        if(stored.find(key) == stored.end()){
            Node* cur = new Node(key, value);
            stored[key] = cur;
            insert(cur);
            size++;
        }else{
            stored[key]->val = value;
            remove(stored[key]);
            insert(stored[key]);
        }
        if(size > cap){
            stored.erase(dummy->next->key);
            Node* lru = dummy->next;
            remove(dummy->next);
            delete lru;
            size--;
        }
    }
};


