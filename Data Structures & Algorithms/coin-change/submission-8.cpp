class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mins(amount+1, amount+1);
        mins[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(coin <= i){
                    mins[i] = min(mins[i-coin]+1, mins[i]);
                }
                
            }
        }
        return mins[amount] > amount ? -1 : mins[amount];
    }
};
