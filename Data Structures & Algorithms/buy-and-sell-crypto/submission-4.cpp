class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(profit < prices[i] - bought){
                profit = prices[i] - bought;
            }
            if(prices[i] - bought < 0){
                bought = prices[i];
            }
        }
        if(profit > 0){
            return profit;
        }else{
            return 0;
        }
    }
};
