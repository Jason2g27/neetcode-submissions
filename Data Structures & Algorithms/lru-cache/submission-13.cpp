struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> loc;
    int cap;
    Node* dummy;
    Node* dummy2;
    LRUCache(int capacity) {
        cap = capacity;
        dummy = new Node();
        dummy2 = new Node();
        dummy->next = dummy2;
        dummy2->prev= dummy;
    }
    
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        Node* last = dummy2->prev;
        last->next = node;
        node->prev = last;
        node->next = dummy2;
        dummy2->prev = node;
    }

    int get(int key) {
        if(loc.find(key) != loc.end()){
            remove(loc[key]);
            insert(loc[key]);
            return loc[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(loc.find(key) == loc.end()){
            if(cap == loc.size()){
                Node* lru = dummy->next; 
                loc.erase(lru->key);   
                remove(lru);             
                delete lru;
            }
            Node* add = new Node(key, value);
            loc[key] = add;
            insert(add);
        }else{
            loc[key]->val = value;
            remove(loc[key]);
            insert(loc[key]);
        }
    }
};
