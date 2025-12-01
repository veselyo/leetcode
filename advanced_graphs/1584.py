class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        class UnionFind:
            def __init__(self, n):
                self.parent = {}
                self.rank = {}
                for i in range(n):
                    self.makeset(i)

            def makeset(self, x):
                self.parent[x] = x
                self.rank[x] = 0

            def find(self, x):
                if self.parent[x] != x:
                    self.parent[x] = self.find(self.parent[x])
                return self.parent[x]

            def union(self, x, y):
                return self.link(self.find(x), self.find(y))

            def link(self, x, y):
                if self.rank[x] < self.rank[y]:
                    return self.link(y, x)
                elif self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.parent[x] = y
                return y

        n = len(points)
        edges = []
        for u in range(n):
            for v in range(u, n):
                edges.append((abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]), u, v))
        edges.sort()
        cost = 0
        uf = UnionFind(n)

        for d, u, v in edges:
            if (uf.find(u) != uf.find(v)):
                cost += d
                uf.union(u, v)

        return cost