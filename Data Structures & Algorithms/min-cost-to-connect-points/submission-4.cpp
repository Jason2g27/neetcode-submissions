class Solution {
public:
    vector<int> parents;
    int find(int i){
        if(parents[i] == i){
            return i;
        }
        return find(parents[i]);
    }
 bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            parents[rootU] = rootV;
            return true;
        }
        return false;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parents.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        // Store edges as {distance, u, v}
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + 
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        // Sort edges by distance (ascending)
        sort(edges.begin(), edges.end());

        int minCost = 0;
        int edgesUsed = 0;

        for (const auto& edge : edges) {
            int dist = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (unionSets(u, v)) {
                minCost += dist;
                edgesUsed++;
                if (edgesUsed == n - 1) break; // MST completed
            }
        }

        return minCost;
    }
};
