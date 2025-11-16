class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        result = []
        for elm in nums:
            if elm not in count:
                count[elm] = 1
            else:
                count[elm] += 1

        buckets = [[] for _ in range(len(nums) + 1)]
        for key, val in count.items():
            buckets[val].append(key)

        for i in range(len(buckets)):
            result.extend(buckets[-i])
            if len(result) == k:
                break
        
        return result