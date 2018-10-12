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
        DFS

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


sol = Solution()
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
