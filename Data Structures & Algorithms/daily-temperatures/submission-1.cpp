class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> warmest;
        vector<int> results(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!warmest.empty() && temperatures[i] > temperatures[warmest.top()]){
                results[warmest.top()] = i - warmest.top();
                warmest.pop();
            }
            warmest.push(i);
        }
        return results;
    }
};
