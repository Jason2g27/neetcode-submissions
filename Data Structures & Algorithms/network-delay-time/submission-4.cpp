class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
        minheap.push({0, k});

        while (!minheap.empty()) {
            auto [d, node] = minheap.top();
            minheap.pop();
            if (d > dist[node]) continue;

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    minheap.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};