class Solution {
public:
    bool checkValidString(string s) {
        int maxCount = 0, minCount = 0;
        for(char c : s){
            if(c == '('){
                maxCount++;
                minCount++;
            }else if(c == ')'){
                maxCount--;
                minCount--;
            }else{
                minCount--;
                maxCount++;
            }
            if(maxCount < 0)return false;
            if(minCount < 0)minCount = 0;
        }
        return minCount == 0;
    }
};
