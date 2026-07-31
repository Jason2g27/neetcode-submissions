/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> nodes;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        dfs(node);
        return nodes[node];
    }

    Node* dfs(Node* node){
        if(nodes.count(node)){
            return nodes[node];
        }
        Node* copy = new Node(node->val);
        nodes[node] = copy;
        for(auto& cur : node->neighbors){
            copy->neighbors.push_back(dfs(cur));
        }
        return copy;
    }
};
