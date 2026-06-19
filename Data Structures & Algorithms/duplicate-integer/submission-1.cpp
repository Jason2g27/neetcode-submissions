class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numsList;
        for(int num : nums){
            if(numsList.contains(num))return true;
            numsList.insert(num);
        }
        return false;
    }
};