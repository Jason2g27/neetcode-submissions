class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> results;
        for(string str : strs){
            vector<int> count(26, 0);
            for(char c : str ){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }
            results[key].push_back(str);
        }
        vector<vector<string>> result;
        for(const auto& pair: results){
            result.push_back(pair.second);
        }
        return result;
    }
};
