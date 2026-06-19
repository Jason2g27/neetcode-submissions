class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for(const auto& num : nums){
            count[num]++;
        }
        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }
        vector<int> answer;
        for(int i = freq.size()-1; i > 0; --i){
            for(int j : freq[i]){
                if(answer.size() == k){
                    return answer;
                }
                answer.push_back(j);
            }
        }
        return answer;
    }
};
