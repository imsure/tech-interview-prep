class Solution:
    def _is_magic_grid(self, grid):
        set_ = set()
        for row in grid:
            for col in row:
                if col not in range(1, 10):
                    return False
                set_.add(col)

        # set = {col for col in row for row in grid}
        # print(set_)
        if len(set_) != 9:
            return False

        s = sum(grid[0])
        for row in grid:
            if sum(row) != s:
                return False

        for i in range(3):
            s_col = grid[0][i] + grid[1][i] + grid[2][i]
            if s_col != s:
                return False

        if grid[0][0] + grid[1][1] + grid[2][2] != s:
            return False

        if grid[0][2] + grid[1][1] + grid[2][0] != s:
            return False

        return True

    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count = 0
        n = len(grid)
        m = len(grid[0])

        for i in range(n - 2):
            for j in range(m - 2):
                subgrid = [grid[i][j:j+3], grid[i+1][j:j+3], grid[i+2][j:j+3]]
                if self._is_magic_grid(subgrid) is True:
                    count += 1

        return count


if __name__ == '__main__':
    sol = Solution()
    print(sol.numMagicSquaresInside([[4,3,8,4],
                                     [9,5,1,9],
                                     [2,7,6,2]]))