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
        unordered_map<Node*, Node*> randoms;
        Node* start = head;
        while(head != nullptr){
            Node* copy = new Node(head->val);
            randoms[head] = copy;
            head = head->next;
        }
        Node* cur = randoms[start];
        Node* result = randoms[start];
        while(start != nullptr){
            cur->random = randoms[start->random];
            cur->next = randoms[start->next];
            cur = cur->next;
            start = start->next;
        }
        return result;
    }
};
