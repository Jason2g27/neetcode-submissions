class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        while(l < r){
            int k = (l+r)/2;
            int count = 0;
            for(auto& p : piles){
                count += ceil(static_cast<double>(p)/k);
            }
            if(count > h){
                l = k+1;
            }
            else{
                r = k;
            }
        }
        return l;
    }
};
