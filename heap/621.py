from collections import Counter
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap)
        
        time = 0
        cooldown = deque()

        while maxHeap or cooldown:
            time += 1

            if not maxHeap:
                time = cooldown[0][1]
            else:
                newCount = 1 + heapq.heappop(maxHeap)
                if newCount:
                    cooldown.append([newCount, time + n])

            if cooldown and cooldown[0][1] == time:
                heapq.heappush(maxHeap, cooldown.popleft()[0])
        
        return time