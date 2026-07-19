class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> count(n + 1, 0);
        count[n] = 1;
        for(int i = s.length()-1; i > -1; i--){
            if(s[i] == '0'){
                count[i] = 0;
            }else{
                if(i == s.length()-1){
                    count[i] = 1;
                    continue;
                }
                count[i] = count[i+1];
                if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7')){
                    count[i] += count[i+2];
                }
            }
        }
        return count[0];
    }
};
