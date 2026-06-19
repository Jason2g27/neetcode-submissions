// Fast I/O optimization block
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.length() - 1;
        
        while (st < e) {
            // 1. Using highly optimized built-in std::isalnum
            while (st < e && !isalnum(s[st])) {
                st++;
            }
            while (e > st && !isalnum(s[e])) {
                e--;
            }
            
            // 2. Fast character case-insensitive check
            if (tolower(s[st]) != tolower(s[e])) {
                return false;
            }
            
            st++; 
            e--;
        }
        return true;
    }
};