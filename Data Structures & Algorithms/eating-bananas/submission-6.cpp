class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l <= r){
            k = (l + r) / 2;
            int time = 0;
            for(int pile : piles){
                time += ceil((double)pile/k);
            }
            if(time <= h){
                r = k - 1;
            }else{
                l = k + 1;
            }
        }
        return l;
    }
};
