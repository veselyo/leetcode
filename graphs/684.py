class UnionFind:
    def __init__(self, n):
        self.parent = {}
        self.rank = {}
        for i in range(1, n + 1):
            self.make_set(i)
    
    def make_set(self, x):
        self.parent[x] = x
        self.rank[x] = 0
    
    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        self.link(self.find(x), self.find(y))
    
    def link(self, x, y):
        if self.rank[x] > self.rank[y]:
            return self.link(y, x)
        if self.rank[x] == self.rank[y]:
            self.rank[y] = self.rank[y] + 1
        self.parent[x] = y
        return y

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UnionFind(len(edges))
        for u, v in edges:
            if uf.find(u) == uf.find(v):
                return [u, v]
            else:
                uf.union(u, v)