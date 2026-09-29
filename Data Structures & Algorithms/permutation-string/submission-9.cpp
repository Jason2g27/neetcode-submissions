class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> match;
        int l = 0;
        for(char c : s1){
            match[c]++;
        }
        unordered_map<char, int> cur;
        for(int r = 0; r < s2.size(); r++){
            if((r-l+1) > s1.length()){
                if(--cur[s2[l]] == 0){
                    cur.erase(s2[l]);
                }
                l++;
            }
            cur[s2[r]]++;
            if(match == cur){
                return true;
            }
        }
        return false;
    }
};
