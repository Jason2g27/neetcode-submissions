class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == target){
                    answers.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    continue;
                }
                if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return answers;
    }
};
