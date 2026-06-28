class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> counts;
        for(char c : s1){
            counts[c]++;
        }
        int l = 0;
        unordered_map<char, int> counts2;
        for(int r = 0; r < s2.length(); r++){
            if((r-l+1) > s1.length()){
                if(--counts2[s2[l]] == 0) counts2.erase(s2[l]);
                l++;
            }
            counts2[s2[r]]++;
            if(counts2 == counts){
                return true;
            }
        }
        return false;
    }
};
