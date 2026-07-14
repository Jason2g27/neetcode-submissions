class Solution {
public:
    unordered_map<char, vector<string>> chars;
    vector<string> results;
    vector<string> letterCombinations(string digits) {
        chars['2'] = {"a", "b", "c"};
        chars['3'] = {"d", "e", "f"};
        chars['4'] = {"g", "h", "i"};
        chars['5'] = {"j", "k", "l"};
        chars['6'] = {"m", "n", "o"};
        chars['7'] = {"p", "q", "r", "s"};
        chars['8'] = {"t", "u", "v"};
        chars['9'] = {"w", "x", "y", "z"};
        if(digits.length() == 0){
            return results;
        }
        traverse(digits, "", 0);
        return results;
    }

    void traverse(string& digits, string cur, int i){
        if(i == digits.length()){
            results.push_back(cur);
            return;
        }
        vector<string> combo = chars[digits[i]];
        for(string s : combo){
            traverse(digits, cur + s, i+1);
        }
    }
};
