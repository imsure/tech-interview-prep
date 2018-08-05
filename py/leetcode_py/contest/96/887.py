class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        area = 0
        for i in range(len(grid)):  # top
            for j in range(len(grid[i])):
                if grid[i][j] > 0:
                    area += 1

        for i in range(len(grid)):
            m = max(grid[i])
            area += m

        for i in range(len(grid[0])):
            m = 0
            for j in range(len(grid)):
                m = max(m, grid[j][i])
            area += m

        return area


sol = Solution()
print(sol.projectionArea([[1,0],[0,2]]))
print(sol.projectionArea([[1,1,1],[1,0,1],[1,1,1]]))
print(sol.projectionArea([[1,0],[0,2]]))

