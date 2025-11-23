import heapq
from math import sqrt

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []

        for [x1, y1] in points:
            curr_dist = -(sqrt((x1 - 0)**2 + (y1 - 0)**2))
            if len(heap) == k:
                if curr_dist > heap[0][0]:
                    heapq.heappop(heap)
                    heapq.heappush(heap, [curr_dist, x1, y1])
            else:
                heapq.heappush(heap, [curr_dist, x1, y1])

        return [[x1, y1] for [_, x1, y1] in heap]