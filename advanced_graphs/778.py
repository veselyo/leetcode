import heapq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dirs = [(0, -1), (1, 0), (0, 1), (-1, 0)]
        pq = [(0, (0, 0))]
        d = [[float('inf') for _ in range(n)] for _ in range(n)]
        d[0][0] = grid[0][0]

        while pq:
            du, u = heapq.heappop(pq)
            if du > d[u[0]][u[1]]:
                continue
            for row, col in dirs:
                if 0 <= u[0] + row < n and 0 <= u[1] + col < n:
                    new_dist = max(grid[u[0] + row][u[1] + col], d[u[0]][u[1]])
                    if d[u[0] + row][u[1] + col] > new_dist:
                        d[u[0] + row][u[1] + col] = new_dist
                        heapq.heappush(pq, (new_dist, (u[0] + row, u[1] + col)))
                
        return d[n-1][n-1]