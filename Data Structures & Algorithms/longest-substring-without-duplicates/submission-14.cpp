class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxLen = 0;
        int left = 0; // Left pointer of our window

        for (int right = 0; right < s.length(); right++) {
            // If the character is already in the window, 
            // shrink the window from the left until the duplicate is removed
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            
            // Add the current character to the window
            seen.insert(s[right]);
            
            // Update the maximum length found so far
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};