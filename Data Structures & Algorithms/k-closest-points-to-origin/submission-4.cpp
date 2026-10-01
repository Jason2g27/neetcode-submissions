class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> distances;
        for(auto& point : points){
                int distance = point[0] * point[0] + point[1] * point[1];
                distances.push({distance, {point[0], point[1]}});
                if(distances.size() > k){
                    distances.pop();
                }
        }
        vector<vector<int>> res;
        while(!distances.empty()){
            auto [dist, point] = distances.top();
            distances.pop();
            res.push_back({point.first, point.second});
        }
        return res;
    }
};



