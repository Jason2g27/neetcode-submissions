class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> sList;
        unordered_map<char, int> tList;
        for(int i =0; i < s.length(); i++){
            sList[s[i]]++;
            tList[t[i]]++;
        }
        return sList == tList;
    }
};
