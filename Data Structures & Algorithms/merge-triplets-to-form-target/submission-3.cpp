class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> res;
        for(auto& triplet : triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                for (int i = 0; i < triplet.size(); i++) {
                    if(triplet[i] == target[i]){
                        res.insert(i);
                    }
                }
            }
        }
        return res.size() == 3;
    }
};
