class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        if n == 0:
            return [newInterval]

        result = []
        inserted = False

        for interval in intervals:
            if interval[1] < newInterval[0]:
                result.append(interval)
            else:
                if not inserted:
                    result.append(newInterval)
                    inserted = True
                if interval[1] >= result[-1][0] and interval[0] <= result[-1][1]:
                    result[-1][0] = min(result[-1][0], interval[0])
                    result[-1][1] = max(result[-1][1], interval[1])
                else:
                    result.append(interval)

        if not inserted:
            result.append(newInterval)

        return result