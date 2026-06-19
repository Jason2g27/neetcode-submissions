class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numsList;
        for(int num : nums){
            if(!numsList.contains(num)){
                numsList.insert(num);
            }else{
                return true;
            }
        }
        return false;
    }
};