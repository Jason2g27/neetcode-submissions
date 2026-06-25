class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        stack<int> combo;
        int i = 0;
        int j = 0;
        while(combo.size() < (nums1.size() + nums2.size())/2+1){
            if(i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])){
                combo.push(nums1[i]);
                i++;
            }else{
                combo.push(nums2[j]);
                j++;
            }
        }
        if((nums1.size() + nums2.size()) % 2 != 0){
            return double(combo.top());
        }else{
            int x = combo.top();
            combo.pop();
            return double(combo.top() + x)/2;
        }
    }
};
