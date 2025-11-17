class Solution:
    def trap(self, height: List[int]) -> int:
        prefix = []
        track_max = 0
        n = len(height)
        for i in range(n):
            prefix.append(track_max)
            track_max = max(height[i], track_max)

        suffix = []
        track_max = 0
        for i in range(n-1, -1, -1):
            suffix.append(track_max)
            track_max = max(height[i], track_max)
        suffix.reverse()

        result = 0
        for i in range(n):
            result += max(min(prefix[i], suffix[i]) - height[i], 0)

        return result