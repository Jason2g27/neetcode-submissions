class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {}

        def dfs(amount: int) -> int:
            if amount == 0:
                return 0
            if amount < 0:
                return -1
            if amount in dp:
                return dp[amount]
            min_coins = float('inf')
            for coin in coins:
                res = dfs(amount-coin)
                if res != -1:
                    min_coins = min(min_coins, res+1)
            dp[amount] = min_coins if min_coins != float('inf') else -1
            return dp[amount]
        return dfs(amount)
        
        
        