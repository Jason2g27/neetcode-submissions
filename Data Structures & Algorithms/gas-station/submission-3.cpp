class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int result = 0;
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))return -1;
        for(int i = 0; i < gas.size(); i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                result = i + 1;
            }
        }
        return result;
    }
};
