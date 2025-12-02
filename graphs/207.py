class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for v, u in prerequisites:
            graph[u].append(v)

        visiting = set()
        visited = set()

        def dfs(node):
            if node in visiting:
                return False
            visiting.add(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    if not dfs(neighbor):
                        return False
            visiting.remove(node)
            visited.add(node)
            return True
        
        for i in range(numCourses):
            if i not in visited and not dfs(i):
                return False
        return True