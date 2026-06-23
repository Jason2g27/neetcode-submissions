class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l < r){
            mid = (l + r) /2;
            if(nums[mid] <= nums[r]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        int pivot = l;
        if(target >= nums[0]){
            l = 0;
            r = (pivot == 0) ? nums.size() - 1 : pivot - 1;
            int mid2;
            while(l <= r){
                mid2 = (l + r)/2;
                if(nums[mid2] == target){
                    return mid2;
                }else if(nums[mid2] < target){
                    l = mid2 + 1;
                }else{
                    r = mid2-1;
                }
            }
        }else{
            l = pivot;
            r = nums.size()-1;
            int mid2;
            while(l <= r){
                mid2 = (l + r)/2;
                if(nums[mid2] == target){
                    return mid2;
                }else if(nums[mid2] < target){
                    l = mid2 + 1;
                }else{
                    r = mid2-1;
                }
            }
        }
        return -1;
    }
};
