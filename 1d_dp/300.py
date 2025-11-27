class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0 for _ in range(n)]
        dp[0] = 1
        max_len = 1

        for i in range(1, n):
            new_max = 1
            for j in range(0, i):
                if nums[j] < nums[i]:
                    new_max = max(new_max, dp[j] + 1)

            dp[i] = new_max
            max_len = max(max_len, new_max)

        return max_len