class Solution {
public:
    vector<bool> store;
    bool wordBreak(string s, vector<string>& wordDict) {
        store.resize(s.length()+1, false);
        store[s.length()] = true;
        for(int i = s.length()-1; i > -1; i--){
            for(string word : wordDict){
                if((i+word.length()) <= s.length() &&s.substr(i, word.length()) == word){
                    store[i] = store[i+word.length()];
                }
                if(store[i]){
                    break;
                }
            }
        }
        return store[0];
    }
};
