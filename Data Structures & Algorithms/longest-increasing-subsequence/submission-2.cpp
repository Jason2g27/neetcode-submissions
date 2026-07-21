class Solution {
public:
    vector<int> store;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        store.resize(n, 1);
        for(int i = n-1; i > -1; i--){
            for(int j = i+1; j < n; j++){
                if(nums[i] < nums[j]){
                    store[i] = max(store[i], store[j]+1);
                }
            }
        }

        return *max_element(store.begin(), store.end());
    }
};
