class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = {}
        
        def backtrack(i, holding):
            if i >= n:
                return 0

            if (i, holding) in dp:
                return dp[(i, holding)]

            max_profit = 0

            if holding:
                max_profit = max(
                    backtrack(i + 1, True),
                    prices[i] + backtrack(i + 2, False)
                )

            else:
                max_profit = max(
                    backtrack(i + 1, False),
                    -prices[i] + backtrack(i + 1, True)
                )

            dp[(i, holding)] = max_profit
            return max_profit

        return backtrack(0, False)