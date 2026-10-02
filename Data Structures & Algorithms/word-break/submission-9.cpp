class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.assign(s.size(), -1);
        return traverse(s, wordDict, 0);
    }

    bool traverse(string& s, vector<string>& wordDict, int i){
        if (i == s.size()) return true;
        if (memo[i] != -1) return memo[i];
        for(auto& word : wordDict){
            if(i + word.size() <= s.size() && s.substr(i, word.size()) == word
            && traverse(s, wordDict, i+word.size())){
                return memo[i] = true;
            }
        }
        return memo[i] = false;
    }
};
