class Solution:
    def sumOfDistancesInTree(self, N, edges):
        """
        Wrong attempt.

        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        p2c, c2p = {}, {}
        for edge in edges:
            p, c = edge
            p2c[p] = p2c.get(p, [])
            p2c[p].append(c)
            c2p[c] = p

        p2c_dist = {}
        for p in p2c:
            p2c_dist[p] = []
            stack = [(c, 1) for c in p2c[p]]
            while stack:
                node, depth = stack.pop()
                p2c_dist[p].append((node, depth))
                if node in p2c:
                    for c in p2c[node]:
                        stack.append((c, depth+1))

        print(p2c_dist)

        ans = [0] * N
        for c, p in c2p.items():
            sum_subtree = 0
            if c in p2c_dist:
                sum_subtree = sum([y for _, y in p2c_dist[c]])
            sum_parent = sum([y for _, y in p2c_dist[p]]) + len(p2c_dist[p]) - (1 + sum_subtree)
            ans[c] = sum_subtree + sum_parent

        for p in p2c:
            if p not in c2p:
                ans[p] = sum([y for _, y in p2c_dist[p]])

        return ans

    def sumOfDistancesInTree2(self, N, edges):
        """
        Brute force, TLE

        Time: O(N^2)
        Space: O(N)

        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        import collections

        ans = [0] * N
        graph = collections.defaultdict(set)
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        def dfs_count(u, v):
            count = 0
            for node in graph[v]:
                if node != u:
                    count += 1 + dfs_count(v, node)
            return count

        def dfs_root_ans(root, depth, parent):
            dist = 0
            for u in graph[root]:
                if u != parent:
                    dist += depth + dfs_root_ans(u, depth+1, root)
            return dist

        def dfs_all(root, ans, parent):
            for u in graph[root]:
                if u != parent:
                    ans[u] = ans[root] + dfs_count(u, root) - dfs_count(root, u)
                    dfs_all(u, ans, root)

        ans[0] = dfs_root_ans(0, 1, -1)  # O(N)
        dfs_all(0, ans, -1)  # O(N^2)

        return ans
        # print(ans[0])
        # print(dfs_count(0, 1))
        # print(dfs_count(0, 2))
        # print(dfs_count(1, 0))

    def sumOfDistancesInTree3(self, N, edges):
        """
        Time: O(N)
        Space: O(N)

        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        import collections

        ans = [0] * N
        count = [0] * N
        graph = collections.defaultdict(set)
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        def dfs_root_ans(root, depth, parent):
            dist = 0
            for u in graph[root]:
                if u != parent:
                    dist += depth + dfs_root_ans(u, depth+1, root)
            return dist

        def dfs_count(root, parent):
            for u in graph[root]:
                if u != parent:
                    count[root] += 1 + dfs_count(u, root)
            return count[root]

        def dfs_all(root, ans, parent):
            for u in graph[root]:
                if u != parent:
                    ans[u] = ans[root] + (N - count[u] - 2) - count[u]
                    dfs_all(u, ans, root)

        ans[0] = dfs_root_ans(0, 1, -1)
        dfs_count(0, -1)
        dfs_all(0, ans, -1)
        # print(ans, count)
        return ans

    def sumOfDistancesInTree4(self, N, edges):
        """
        Improved efficiency: removed one unnecessary traversal. We can compute
        ans[0] during dfs_count.

        Time: O(N)
        Space: O(N)

        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        import collections

        ans = [0] * N
        count = [0] * N
        graph = collections.defaultdict(set)
        for edge in edges:
            u, v = edge
            graph[u].add(v)
            graph[v].add(u)

        def dfs_count(root, parent, depth):
            for u in graph[root]:
                if u != parent:
                    ans[0] += depth
                    count[root] += 1 + dfs_count(u, root, depth+1)
            return count[root]

        def dfs_all(root, parent):
            for u in graph[root]:
                if u != parent:
                    ans[u] = ans[root] + (N - count[u] - 2) - count[u]
                    dfs_all(u, root)

        dfs_count(0, -1, 1)
        dfs_all(0, -1)
        return ans


sol = Solution()
print(sol.sumOfDistancesInTree4(6, [[0,1],[0,2],[2,3],[2,4],[2,5]]))  # [8, 12, 6, 10, 10, 10]
