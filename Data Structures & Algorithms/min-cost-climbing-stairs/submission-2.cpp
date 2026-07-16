class Solution {
public:
    vector<int> mins;
    int minCostClimbingStairs(vector<int>& cost) {
        mins.resize(cost.size(), -1);
        return(min(climb(cost, 0), climb(cost, 1)));
    }

    int climb(vector<int>&cost, int i){
        if(i >= cost.size()) return 0;
        if(mins[i] != -1) return mins[i];
        return mins[i] = cost[i] + min(climb(cost, i+1), climb(cost, i+2));
    }
};
