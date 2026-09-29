class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for (int i = 0; i < position.size(); i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), greater<>());
        stack<double> line;
        for(auto& [pos, spe] : car){
            double time = (double)(target-pos) / spe;
            if (line.empty() || time > line.top()) {
                line.push(time);
            }
        }
        return line.size();
    }
};
