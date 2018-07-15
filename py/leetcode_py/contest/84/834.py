class Solution:
    def dist(self, n, edge_set):
        distance = 0
        N = len(edge_set) + 1
        for i in range(0, N):
            if (n, i) in edge_set:
                distance += 1
                sub_dist = self.dist(i, edge_set)
                size = 0
                for edge in edge_set:
                    if edge[0] == i:
                        size += 1
                if sub_dist:
                    distance += size + sub_dist

        return distance

    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        edge_set = set()
        for edge in edges:
            edge_set.add((edge[0], edge[1]))

        # print(edge_set)
        ans = []
        for i in range(0, N):
            ans.append(self.dist(i, edge_set))

        print(ans)

        for i in range(0, N):
            edge_set2 = set(edge_set)
            for edge in edge_set2:
                if edge[1] == i:
                    edge = (edge[1], edge[0])
            ans[i] += self.dist(i, edge_set2)

        return ans


if __name__ == '__main__':
    sol = Solution()
    ans = sol.sumOfDistancesInTree(6, [[0,1],[0,2],[2,3],[2,4],[2,5]])
    print(ans)