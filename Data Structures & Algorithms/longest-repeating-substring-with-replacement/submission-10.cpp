class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int l = 0, result = 0;
        int maxFreq = 0;
        for(int r = 0; r < s.length(); r++){
            counts[s[r]]++;
            maxFreq = max(maxFreq, counts[s[r]]);
            while((r-l+1)-maxFreq > k){
                counts[s[l]]--;
                l++;
            }
            result = max(result, (r-l+1));
        }
        return result;
    }
};
