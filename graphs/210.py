class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        print(len(graph))
        for v, u in prerequisites:
            graph[u].append(v)
        
        def topological_sort(graph):
            visiting = set()
            visited = set()
            result = []

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
                result.append(node)

                return True

            for node in range(len(graph)):
                if node not in visited:
                    if not dfs(node):
                        return []

            return result[::-1]

        return topological_sort(graph)