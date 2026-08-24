class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> freq(n+1);
        for(auto& time : times){
            freq[time[0]].push_back({time[2], time[1]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        unordered_map<int, bool> visited;
        int res = 0;
        while(!q.empty()){
            auto [time, value] = q.top();
            q.pop();
            if(visited[value]){
                continue;
            }
            res = time;
            visited[value] = true;
            for(auto& edge : freq[value]){
                q.push({edge.first + time, edge.second});
            }
        }
        return visited.size() == n ? res : -1;
    }
};
