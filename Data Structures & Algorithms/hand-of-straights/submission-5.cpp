class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> counts(hand.size());
        for(int i = 0; i < hand.size(); i++){
            counts[hand[i]]++;
        }
        for(auto& num : hand){
            if(counts[num] > 0){
                int j = num;
                while(j < num+groupSize){
                    if(counts[j] == 0){
                        return false;
                    }
                    counts[j]--;
                    j++;
                }
            }
        }

        return true;
    }
};
