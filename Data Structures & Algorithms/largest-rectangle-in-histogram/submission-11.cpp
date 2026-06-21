class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> box;
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        int max = 0;
        for(int i = 0; i < n; i++){
            while(!box.empty() && heights[i] <= heights[box.top()]){
                box.pop();
            }
            if(!box.empty()){
                left[i] = box.top();
            }
            box.push(i);
        }
        while (!box.empty()) box.pop();
        for (int i = n - 1; i >= 0; i--) {
            while(!box.empty() && heights[i] <= heights[box.top()]){
                box.pop();
            }
            if(!box.empty()){
                right[i] = box.top();
            }
            box.push(i);
        }
        for(int i = 0; i < n; i++){
            max = std::max(max, (heights[i] * (right[i]-left[i]-1)));
        }
        return max;
    }
};
