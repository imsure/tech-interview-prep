class Solution:
    def _dfs(self, graph, visited, node, color, color_map):
        if node in visited:
            return True

        visited.add(node)
        color_map[node] = color
        next_color = 1 if color == 0 else 0
        for n in graph[node]:
            if n in visited and color_map[n] == color:
                return False

            if n not in visited:
                r = self._dfs(graph, visited, n, next_color, color_map)
                if not r:
                    return False

        return True

    def possibleBipartition(self, N, dislikes):
        """
        Build an undirected graph from the input and DFS each connected component.
        For each connected component, try to color each node such that no two adjacent
        nodes are of the same color (two-coloring). If anytime there is a violation, return False.

        Time: O(|V| + |E|), need to traverse the entire graph
        Space: O(|V| + |E|)

        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        graph = {}
        for p1, p2 in dislikes:
            graph[p1] = graph.get(p1, [])
            graph[p1].append(p2)
            graph[p2] = graph.get(p2, [])
            graph[p2].append(p1)

        visited = set()
        color = 0
        color_map = {}
        for p in graph.keys():
            r = self._dfs(graph, visited, p, color, color_map)
            if not r:
                return False

        return True


sol = Solution()
print(sol.possibleBipartition(4, [[1,2],[1,3],[2,4]]))  # True
print(sol.possibleBipartition(3, [[1,2],[1,3],[2,3]]))  # False
print(sol.possibleBipartition(5, [[1,2],[2,3],[3,4],[4,5],[1,5]]))  # False
print(sol.possibleBipartition(10, [[5,9],[5,10],[5,6],[5,7],[1,5],[4,5],[2,5],[5,8],[3,5]]))  # True
