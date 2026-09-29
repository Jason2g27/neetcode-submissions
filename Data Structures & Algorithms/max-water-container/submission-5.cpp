class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int result = 0;
        while(l < r){
            result = max(result, (r-l) * min(heights[l], heights[r]));
            if(heights[l] <= heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return result;
    }
};
