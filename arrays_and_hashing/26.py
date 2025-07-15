class Solution(object):
    def removeDuplicates(self, nums):
        unique = []
        size = len(nums)
        for i in range(size - 1):
            if nums[i] != nums[i+1]:
                unique.append(i)
        unique.append(size - 1)
        k = len(unique)
        for i in range(k):
            nums[i] = nums[unique[i]]
        return k