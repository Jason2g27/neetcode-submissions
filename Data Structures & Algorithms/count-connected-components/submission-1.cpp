class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int components = n;
        for(auto& edge : edges){
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);
            if(root1 != root2){
                parent[root1] = root2;
                components--;
            }
        }
        return components;
    }
};
