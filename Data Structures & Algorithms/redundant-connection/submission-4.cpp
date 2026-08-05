class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        for(int i = 0; i < edges.size(); i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            int r1 = find(edge[0]);
            int r2 = find(edge[1]);
            if(r1 == r2){
                return edge;
            }
            parent[r2] = r1;
        }
        return {};
    }
};
