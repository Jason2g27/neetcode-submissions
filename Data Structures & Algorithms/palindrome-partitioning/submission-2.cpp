class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        traverse(s, cur, 0, 0);
        return res;
    }

    void traverse(string& s, vector<string>& cur, int l, int r){
        if(r == s.size()){
            if(l == r){
                res.push_back(cur);
            }
            return;
        }
        if(isPalindrome(l, r, s)){
            cur.push_back(s.substr(l, r-l+1));
            traverse(s, cur, r+1, r+1);
            cur.pop_back();
        }
        traverse(s, cur, l, r+1);
    }

    bool isPalindrome(int l, int r, string& s){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
