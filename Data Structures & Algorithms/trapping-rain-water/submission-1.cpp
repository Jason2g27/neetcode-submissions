class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> lMax(n);
        vector<int> rMax(n);
        lMax[0] = height[0];
        for(int i = 1; i < n; i++){
            lMax[i] = max(lMax[i-1], height[i]);
        }
        rMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rMax[i] = max(rMax[i+1], height[i]);
        }
        int water = 0;
        for(int i = 0; i < n; i++){
            water += (min(lMax[i], rMax[i]) - height[i]);
        }
        return water;
    }
};
