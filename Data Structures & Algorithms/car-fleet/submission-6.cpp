class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> fleets;
        map<int, int, greater<int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars[position[i]] = speed[i];
        }
        float time = 0;
        for(pair<int, int> car : cars){
            time = (target-car.first)/(float)car.second;
            if(fleets.empty() || time > fleets.top()){
                fleets.push(time);
            }
        }
        return fleets.size();
    }
};
