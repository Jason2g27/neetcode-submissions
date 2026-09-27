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
        int n = edges.size()+1;
        parent.resize(n);
        for(int i = 1; i < n; i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            if(find(edge[0]) != find(edge[1])){
                parent[find(edge[0])] = parent[find(edge[1])];
            }else{
                return edge;
            }
        }
    }
};



