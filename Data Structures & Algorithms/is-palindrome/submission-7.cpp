class Solution {
public:
    bool isPalindrome(string s) {
        // Use raw character pointers for direct memory access
        const char* st = s.data();
        const char* e = st + s.length() - 1;
        
        while (st < e) {
            while (st < e && !isalnum(*st)) {
                st++;
            }
            while (st < e && !isalnum(*e)) {
                e--;
            }
            
            if (st < e) {
                // Bitwise trick: '| 32' forces 'A'-'Z' into 'a'-'z' range.
                // We only do this if they aren't already identical.
                if (*st != *e && (*st | 32) != (*e | 32)) {
                    return false;
                }
                st++;
                e--;
            }
        }
        return true;
    }
};