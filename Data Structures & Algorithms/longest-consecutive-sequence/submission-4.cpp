class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sorted(nums.begin(), nums.end());
        int longest = 0;
        int curr = 1;
        for(int num : sorted){
            if(sorted.find(num-1) == sorted.end()){
                while(sorted.find(num+curr) != sorted.end()){
                    curr++;
                }
                if(curr > longest)longest = curr;
                curr = 0;
            }
        }
        return longest;
    }
};
