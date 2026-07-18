class Solution {
public:
    string longestPalindrome(string s) {
        int start, end = 0;
        int n = s.length();
        vector<vector<bool>> order(n, vector<bool>(n, false));
        for(int i = n-1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j-i <= 2 || order[i+1][j-1])){
                    order[i][j] = true;
                    if(j-i > end - start){
                        end = j;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};
