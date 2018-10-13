class Solution:
    def dfs(self, matrix, i, j, path_len):
        longest_inc_path = path_len
        n = len(matrix)
        m = len(matrix[0])
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dx, dy in dirs:
            if 0 <= i + dx < n and 0 <= j + dy < m and matrix[i+dx][j+dy] > matrix[i][j]:
                ret = self.dfs(matrix, i+dx, j+dy, path_len+1)
                longest_inc_path = max(longest_inc_path, ret)

        return longest_inc_path

    def longestIncreasingPath(self, matrix):
        """
        Brute force DFS

        :type matrix: List[List[int]]
        :rtype: int
        """
        ans = 0
        n = len(matrix)
        if n == 0:
            return ans
        m = len(matrix[0])

        for i in range(n):
            for j in range(m):
                path_len = 1
                longest_inc_path = self.dfs(matrix, i, j, path_len)
                ans = max(ans, longest_inc_path)

        return ans


class Solution2:
    """
    DP + DFS, update LIP of each entry dynamically so that we can reuse the results.
    """

    def dfs(self, matrix, i, j, cur_path_len, lip_map):
        longest_inc_path = cur_path_len
        n = len(matrix)
        m = len(matrix[0])
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dx, dy in dirs:
            nx, ny = i + dx, j + dy
            if 0 <= nx < n and 0 <= ny < m and matrix[nx][ny] > matrix[i][j]:
                if (nx, ny) in lip_map:
                    tmp_len = cur_path_len + lip_map[(nx, ny)]
                else:
                    tmp_len = self.dfs(matrix, nx, ny, cur_path_len+1, lip_map)
                longest_inc_path = max(longest_inc_path, tmp_len)

        lip_map[(i, j)] = max(lip_map[(i, j)], longest_inc_path - cur_path_len + 1)
        return longest_inc_path

    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        import collections

        ans = 0
        n = len(matrix)
        if n == 0:
            return ans
        m = len(matrix[0])
        lip_map = collections.defaultdict(int)

        for i in range(n):
            for j in range(m):
                cur_path_len = 1
                longest_inc_path = self.dfs(matrix, i, j, cur_path_len, lip_map)
                lip_map[(i, j)] = longest_inc_path
                ans = max(ans, longest_inc_path)

        return ans


class Solution3:
    """
    Use array to store computed results.
    DP + DFS, update LIP of each entry dynamically so that we can reuse the results.
    """

    def dfs(self, matrix, i, j, cur_path_len, dp):
        longest_inc_path = cur_path_len
        n = len(matrix)
        m = len(matrix[0])
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dx, dy in dirs:
            nx, ny = i + dx, j + dy
            if 0 <= nx < n and 0 <= ny < m and matrix[nx][ny] > matrix[i][j]:
                if dp[nx][ny] > 0:
                    tmp_len = cur_path_len + dp[nx][ny]
                else:
                    tmp_len = self.dfs(matrix, nx, ny, cur_path_len+1, dp)
                longest_inc_path = max(longest_inc_path, tmp_len)

        dp[i][j] = longest_inc_path - cur_path_len + 1
        return longest_inc_path

    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        ans = 0
        n = len(matrix)
        if n == 0:
            return ans
        m = len(matrix[0])
        dp = [[0] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                cur_path_len = 1
                longest_inc_path = self.dfs(matrix, i, j, cur_path_len, dp)
                ans = max(ans, longest_inc_path)

        return ans


sol = Solution3()
nums1 = [
    [9,9,4],
    [6,6,8],
    [2,1,1]
]
print(sol.longestIncreasingPath(nums1))  # 4
nums2 = [
    [3,4,5],
    [3,2,6],
    [2,2,1]
]
print(sol.longestIncreasingPath(nums2))  # 4

nums3 = [[0,1,2,3,4,5,6,7,8,9],[19,18,17,16,15,14,13,12,11,10],[20,21,22,23,24,25,26,27,28,29],[39,38,37,36,35,34,33,32,31,30],[40,41,42,43,44,45,46,47,48,49],[59,58,57,56,55,54,53,52,51,50],[60,61,62,63,64,65,66,67,68,69],[79,78,77,76,75,74,73,72,71,70],[80,81,82,83,84,85,86,87,88,89],[99,98,97,96,95,94,93,92,91,90],[100,101,102,103,104,105,106,107,108,109],[119,118,117,116,115,114,113,112,111,110],[120,121,122,123,124,125,126,127,128,129],[139,138,137,136,135,134,133,132,131,130],[0,0,0,0,0,0,0,0,0,0]]
print(sol.longestIncreasingPath(nums3))  # 140
