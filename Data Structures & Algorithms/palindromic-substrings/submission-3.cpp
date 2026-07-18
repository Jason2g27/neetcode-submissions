class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<bool>> order(n, vector<bool>(n, false));
        for(int i = n-1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j-i <= 2 || order[i+1][j-1])){
                    order[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
