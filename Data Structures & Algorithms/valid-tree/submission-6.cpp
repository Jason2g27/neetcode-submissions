class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adjacent(n);
        for(auto& edge : edges){
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        int visitCount = 0;
        if(!dfs(0, -1, adjacent, visited)){
            return false;
        }
        for (int v : visited) {
            if (v == 1) visitCount++;
        }

        return visitCount == n;
    }

    bool dfs(int n, int p, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[n] == 1){
            return false;
        }
        visited[n] = 1;
        for(auto& edge : adj[n]){
            if(edge == p){
                continue;
            }
            if(!dfs(edge, n, adj, visited)){
                return false;
            }
        }
        return true;
    }
};
