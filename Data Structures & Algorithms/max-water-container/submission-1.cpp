class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int answer = 0;
        while(left < right){
            int volume = min(heights[left], heights[right]) * (right - left);
            answer = max(answer, volume);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return answer;
    }
};
