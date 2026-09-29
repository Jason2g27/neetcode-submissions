class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(target >= matrix[mid][0]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if (r < 0) return false;
        int col_l = 0;
        int col_r = matrix[r].size()-1;
        int col_mid;
        while(col_l <= col_r){
            col_mid = (col_l + col_r) / 2;
            if(matrix[r][col_mid] == target){
                return true;
            }else if(matrix[r][col_mid] < target){
                col_l = col_mid+1;
            }else{
                col_r = col_mid-1;
            }
        }
        return false;
    }
};
