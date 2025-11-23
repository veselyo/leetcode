class Solution:
    result = []

    def backtrack(self, nums, curr_nums, curr_perm):
        if len(curr_perm) == len(nums):
            self.result.append(curr_perm.copy())
            return
        
        for num in nums:
            if num not in curr_nums:
                curr_nums.add(num)
                curr_perm.append(num)
                self.backtrack(nums, curr_nums, curr_perm)
                curr_nums.remove(num)
                curr_perm.pop()

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.result = []
        self.backtrack(nums, set(), [])

        return self.result