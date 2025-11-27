class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 1

        for idx in range(1, n + 1):
            for amt in range(amount + 1):
                dp[idx][amt] = dp[idx-1][amt]
                
                if amt >= coins[idx-1]:
                    dp[idx][amt] += dp[idx][amt - coins[idx-1]]
        
        return dp[n][amount]