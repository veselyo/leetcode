import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dist = [[float('inf')] * (k + 2) for _ in range(n)]
        graph = [[] for _ in range(n)]

        for u, v, d in flights:
           graph[u].append((d, v))

        dist[src][0] = 0
        pq = [(0, src, 0)]

        while pq:
            d, u, stops = heapq.heappop(pq)

            if u == dst:
                return d

            if stops > k:
                continue

            if d > dist[u][stops]:
                continue

            for length, v in graph[u]:
                if dist[v][stops + 1] > d + length:
                    dist[v][stops + 1] = d + length
                    heapq.heappush(pq, (d + length, v, stops + 1))

        return -1