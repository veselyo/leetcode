class Solution:
    def bsearch(self, left, right, nums, target):
        while(left <= right):
            middle = left + ((right - left) // 2)
            if nums[middle] == target:
                return middle
            elif nums[middle] > target:
                right = middle - 1
            else:
                left = middle + 1
        return -1

    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while (left < right):
            middle = left + ((right - left) // 2)
            if nums[middle] > nums[right]:
                left = middle + 1
            else:
                right = middle
        min_idx = left

        left = 0
        right = len(nums) - 1
        if min_idx == 0:
            return self.bsearch(left, right, nums, target)
        elif target >= nums[0] and target <= nums[min_idx - 1]:
            return self.bsearch(left, min_idx - 1, nums, target)
        else:
            return self.bsearch(min_idx, right, nums, target)