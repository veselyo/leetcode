class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        for num in nums:
            maxSum = max(maxSum, num)
        
        runningSum = 0
        for num in nums:
            runningSum += num
            maxSum = max(maxSum, runningSum)
            if runningSum < 0:
                runningSum = 0
        return maxSum