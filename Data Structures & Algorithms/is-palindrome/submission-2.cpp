class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.length()-1;
        while(st < e){
            while (st < e && !alphaNum(s[st])) {
                st++;
            }
            while (e > st && !alphaNum(s[e])) {
                e--;
            }
            if(tolower(s[st]) != tolower(s[e]))return false;
            st++; e--;
        }
        return true;
    }


    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
