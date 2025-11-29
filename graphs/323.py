class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
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
                self.link(self.find(x), self.find(y))

            def link(self, x, y):
                if self.rank[x] > self.rank[y]:
                    return self.link(y, x)
                elif self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                self.parent[x] = y
                return y

        uf = UnionFind(n)
        for [u, v] in edges:
            uf.union(u, v)

        components = set()

        for i in range(n):
            components.add(uf.find(i))

        return len(components)