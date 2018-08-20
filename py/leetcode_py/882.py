class Solution:
    def reachableNodes(self, edges, M, N):
        """
        Wrong attempt: simple BFS would not work because we need to find out
        all the nodes that are reachable from node 0 along shortest path.

        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        node_num = N
        new_edges = []
        for edge in edges:
            i, j, n = edge
            if n == 0:
                new_edges.append([i, j])
            else:
                new_edges.append([i, node_num])
                new_edges.append([node_num + n - 1, j])
                for k in range(0, n-1):
                    new_edges.append([node_num + k, node_num + k + 1])

            node_num += n

        # print(new_edges)

        graph = {}
        for edge in new_edges:
            u, v = edge
            graph[u] = graph.get(u, [])
            graph[u].append(v)
            graph[v] = graph.get(v, [])
            graph[v].append(u)

        # print(graph)

        if 0 not in graph:
            return 1  # can at least reach 0 itself

        q = [(0, 0)]  # initial state: node 0 at move 0
        visited = set()
        added = set()
        node_count = 1
        while q:
            u, m = q.pop()
            if m >= M or u in visited:
                continue

            for v in graph[u]:
                if v not in visited and v not in added:
                    node_count += 1
                    # print('parent node: {}, adding node {}'.format(u, v))
                    # print(visited)
                    added.add(v)
                    q.append((v, m + 1))
            visited.add(u)

        return node_count

    def reachableNodes2(self, edges, M, N):
        """
        Dijkstra: calculate the shortest distance from node 0 to all other nodes
        and count the number of nodes with distance <= M.

        TLE: reconstructing graph is too time consuming!

        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        import sys
        import heapq

        node_num = N
        new_edges = []
        for edge in edges:
            i, j, n = edge
            if n == 0:
                new_edges.append([i, j])
            else:
                new_edges.append([i, node_num])
                new_edges.append([node_num + n - 1, j])
                for k in range(0, n-1):
                    new_edges.append([node_num + k, node_num + k + 1])

            node_num += n

        graph = {}
        for edge in new_edges:
            u, v = edge
            graph[u] = graph.get(u, [])
            graph[u].append(v)
            graph[v] = graph.get(v, [])
            graph[v].append(u)

        # initial distance to node 0
        dist = [sys.maxsize] * node_num
        dist[0] = 0

        pq = [(dist[0], 0)]
        visited = set()
        while pq:
            d, u = heapq.heappop(pq)
            if u in visited or u not in graph:
                continue

            for v in graph[u]:
                if v in visited:
                    continue
                if d + 1 < dist[v]:  # relax
                    dist[v] = d + 1
                    heapq.heappush(pq, (d + 1, v))
            visited.add(u)

        ans = 0
        for d in dist:
            if d <= M:
                ans += 1

        # print(dist)
        return ans

    def reachableNodes3(self, edges, M, N):
        """
        Treat the original graph as an undirected graph with each edge weighted as
        the number of new nodes on the edge.

        We use Dijkstra's algorithm to find all the nodes reachable within `M` moves,
        the tricky part is to keep track of how many new nodes are reachable on each edge.

        Dijkstra: calculate the shortest distance from node 0 to all other nodes
        and count the number of nodes with distance <= M.

        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        import sys
        import heapq

        graph = {i: [] for i in range(N)}
        for edge in edges:
            u, v, w = edge
            graph[u].append((v, w + 1))
            graph[v].append((u, w + 1))

        reach_count = 0
        dist = [sys.maxsize] * N
        dist[0] = 0
        pq = []
        visited = set()
        heapq.heappush(pq, (0, 0))
        while pq:
            d, u = heapq.heappop(pq)
            if u in visited:
                continue
            for nei in graph[u]:
                v, w = nei
                if v in visited:
                    continue
                if d + w < dist[v]:
                    dist[v] = d + w
                    heapq.heappush(pq, (dist[v], v))
                # reach_count += max(0, min(M - d, w - 1))
            visited.add(u)

        edge_visited = {}
        for u, d in enumerate(dist):
            if d <= M:
                reach_count += 1
                for nei in graph[u]:
                    v, w = nei
                    w_count = min(M - d, w - 1)
                    if (u, v) not in edge_visited and (v, u) not in edge_visited:
                        reach_count += w_count
                        edge_visited[(u, v)] = w_count
                    else:
                        exist_count = edge_visited[(u, v)] if (u, v) in edge_visited else edge_visited[(v, u)]
                        reach_count += min(w - 1 - exist_count, M - d)

        return reach_count


sol = Solution()
print(sol.reachableNodes3([[0,1,10],[0,2,1],[1,2,2]], 6, 3))  # 13
print(sol.reachableNodes3([[0,1,4],[1,2,6],[0,2,8],[1,3,1]], 10, 4))  # 23
print(sol.reachableNodes3([[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], 17 ,5))  # 1
print(sol.reachableNodes3([[2,4,2],[3,4,5],[2,3,1],[0,2,1],[0,3,5]], 14, 5))  # 18
