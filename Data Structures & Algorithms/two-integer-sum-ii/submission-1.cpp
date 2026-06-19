// Fast I/O block to speed up LeetCode's judge system
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        
        // Safer condition: terminates if pointers cross
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            
            if (sum == target) {
                return {i + 1, j + 1};
            }
            
            if (sum > target) {
                j--; // Sum is too big, move the right pointer left
            } else {
                i++; // Sum is too small, move the left pointer right
            }
        }
        
        return {}; // Return empty vector if no solution exists
    }
};