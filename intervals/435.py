class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        result = 0
        n = len(intervals)

        if n == 1:
            return 0

        intervals.sort(key = lambda x: x[0])

        prevInterval = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] < prevInterval[1]:
                if intervals[i][1] < prevInterval[1]:
                    prevInterval = intervals[i]
                result += 1
            else:
                prevInterval = intervals[i]

        return result