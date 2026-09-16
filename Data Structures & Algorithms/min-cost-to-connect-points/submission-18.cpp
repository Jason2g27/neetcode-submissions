class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, int> tracked;
        vector<vector<pair<int, int>>> adj(points.size());
        for(int i = 0; i < points.size();i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < points.size(); j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                adj[i].push_back({abs(x1-x2) + abs(y1-y2), j});
                adj[j].push_back({abs(x1-x2) + abs(y1-y2), i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        int cost = 0;
        while(!q.empty()){
            auto [pointCost, point] = q.top();
            q.pop();
            if(tracked[point] == 1)continue;
            tracked[point] = 1;
            cost += pointCost;
            for(auto& point : adj[point]){
                q.push(point);
            }
        }
        return cost;
    }
};
