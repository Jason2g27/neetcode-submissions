class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int t = 0;
        int b = matrix[0].size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(matrix[mid][t] <= target && matrix[mid][b] >= target){
                while(t <= b){
                    int mid2 = (t+b)/2;
                    if(matrix[mid][mid2] == target){
                        return true;
                    }
                    else if(matrix[mid][mid2] > target){
                        b = mid2-1;
                    }else{
                        t = mid2+1;
                    }
                }
                return false;
            }
            else if(matrix[(l+r)/2][0] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
};
