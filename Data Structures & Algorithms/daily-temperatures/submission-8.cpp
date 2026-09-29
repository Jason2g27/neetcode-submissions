class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> warm;
        vector<int> results(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!warm.empty() && temperatures[i] > temperatures[warm.top()]){
                results[warm.top()] = i - warm.top();
                warm.pop();
            }
            warm.push(i);
        }
        return results;
    }
};
