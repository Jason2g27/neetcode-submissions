class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        for(int i = 0; i < points.size()-1; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < points.size(); j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                adj[i].push_back(pair{abs(x1-x2) + abs(y1-y2), j});
                adj[j].push_back(pair{abs(x1-x2) + abs(y1-y2), i});
            }
        }
        unordered_map<int, bool> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        int cost = 0;
        while(!q.empty()){
            auto [distance, value] = q.top();
            q.pop();
            if(visited[value]){
                continue;
            }
            cost += distance;
            visited[value] = true;
            for(auto& coord : adj[value]){
                q.push(coord);
            }
        }
        return cost;
    }
};
