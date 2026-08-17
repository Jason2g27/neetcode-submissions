class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return dfs(prices, true, 0);
    }

    int dfs(vector<int>& prices, bool buy, int i){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int cd = dfs(prices, buy, i+1);
        if(buy){
            return dp[i][buy] = max(cd, dfs(prices, !buy, i+1) - prices[i]);
        }else{
            return dp[i][buy] = max(cd, dfs(prices, !buy, i+2) + prices[i]);
        }
    }
};
