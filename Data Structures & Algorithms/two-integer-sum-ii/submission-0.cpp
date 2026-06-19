class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        int sum = 0;
        while(sum != target){
            sum = numbers[i] + numbers[j];
            if(sum == target){
                return {i+1, j+1};
            }
            if(sum > target){
                j--;
            }else{
                i++;
            }
        }
    }
};
