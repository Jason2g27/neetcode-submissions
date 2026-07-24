class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> greatest;
        for(auto& point: points){
            int distance = point[0] * point[0] + point[1] * point[1];
            greatest.push({distance, {point[0], point[1]}});
            if(greatest.size() > k){
                greatest.pop();
            }
        }

        vector<vector<int>> res;
        while(!greatest.empty()){
            res.push_back({greatest.top().second.first, greatest.top().second.second});
            greatest.pop();
        }
        return res;
    }
};
