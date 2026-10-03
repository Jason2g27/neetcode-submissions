class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& time : times){
            adj[time[0]].push_back({time[2], time[1]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        vector<int> visited(n+1, 0);
        int result = 0;
        int count = 0;
        while(!q.empty()){
            auto [time, dest] = q.top();
            q.pop();
            if(visited[dest]){
                continue;
            }
            result = time;
            visited[dest] = 1;
            count++;
            for(auto& next : adj[dest]){
                q.push({time+next.first, next.second});
            }
        }
        return count == n ? result : -1;
    }
};
