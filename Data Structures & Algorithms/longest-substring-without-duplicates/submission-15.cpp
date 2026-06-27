class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> cur;
        int l = 0;
        int result = 0;
        for(int r = 0; r < s.length(); r++){
            while(cur.count(s[r])){
                cur.erase(s[l]);
                l++;
            }
            cur.insert(s[r]);
            result = max(result, r-l + 1);
        }
        return result;
    }
};
