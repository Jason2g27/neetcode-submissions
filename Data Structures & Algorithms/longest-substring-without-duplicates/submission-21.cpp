class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int result = 0;
        unordered_set<char> cur;
        while(r != s.length()){
            while(cur.count(s[r])){
                cur.erase(s[l]);
                l++;
            }
            cur.insert(s[r]);
            result = max(result, r-l+1);
            r++;
        }
        return result;
    }
};
