class Solution:
    def projectionArea(self, grid):
        """
        Note: grid is N * N

        Top projection: any grid[i][j] > 0 will be projected with area of 1
        Side projection: the projected area for each row would the largest element in the row
        Front projection: the projected area for each column would the largest element in the column

        Time: O(N^2)
        Space: O(N)

        :type grid: List[List[int]]
        :rtype: int
        """
        area = 0
        col_max = [0] * len(grid[0])
        for row in grid:
            for i, elem in enumerate(zip(row, col_max)):
                if elem[0] > elem[1]:
                    col_max[i] = elem[0]

            row_max = 0
            for col in row:
                if col > 0:
                    area += 1
                    row_max = max(row_max, col)
            area += row_max

        area += sum(col_max)
        return area

    def projectionArea2(self, grid):
        """
        Reduced space complexity. Take advantage that grid's dimension is N*N.

        Time: O(N^2)
        Space: O(1)

        :param grid:
        :return:
        """
        N = len(grid)
        area = 0
        for i in range(N):
            row_max, col_max = 0, 0
            for j in range(N):
                if grid[i][j] > 0:
                    area += 1
                    row_max = max(row_max, grid[i][j])
                col_max = max(col_max, grid[j][i])

            area += row_max + col_max

        return area


sol = Solution()
print(sol.projectionArea2([[2]]))  # 5
print(sol.projectionArea2([[1,2],[3,4]]))  # 17
print(sol.projectionArea2([[1,0],[0,2]]))  # 8
print(sol.projectionArea2([[1,1,1],[1,0,1],[1,1,1]]))  # 14
print(sol.projectionArea2([[2,2,2],[2,1,2],[2,2,2]]))  # 21
print(sol.projectionArea2([[1,0],[5,4]]))  # 18

