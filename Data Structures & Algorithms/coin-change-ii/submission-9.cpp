class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(), vector<int>(amount+1, -1));
        return dfs(amount, coins, 0);
    }

    int dfs(int amount , vector<int>& coins, int i){
        if(amount == 0){
            return 1;
        }
        if (amount < 0 || i >= coins.size()) return 0;
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int res = 0;
        for(int j = i; j < coins.size(); j++){
            res += dfs(amount-coins[j], coins, j);
        }
        return dp[i][amount] = res;
    }
};
