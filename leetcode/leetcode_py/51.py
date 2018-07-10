class Solution:

    def _board_gen(self, queens):
        n = len(queens)
        board = []
        for row, queen in enumerate(queens):
            cur_row = ['.'] * n
            cur_row[queen] = 'Q'
            board.append(''.join(cur_row))
        return board

    def _backtrack(self, queens, row, sols):
        if row == len(queens):
            sols.append(self._board_gen(queens))
            return

        n = len(queens)
        for col in range(n):
            is_valid = True
            for r_prev in range(row):
                cond1 = col == queens[r_prev]  # column check
                cond2 = col == queens[r_prev] + (row - r_prev)  # right-side diagonal check
                cond3 = col == queens[r_prev] - (row - r_prev)  # right-side diagonal check
                if cond1 or cond2 or cond3:
                    is_valid = False

            if is_valid:
                queens[row] = col
                self._backtrack(queens, row + 1, sols)
                queens[row] = -1  # reset

    def solveNQueens(self, n):
        """
        Backtracking:

        according to the rule, there should be exactly one queue on each row,
        so we use a list queue[n] to represent queue's position (column index) on each row.
        queue[i] = j means that a queue is placed on i_th row and j_th column.

        Starting from row 0, column 0, we try every possible queue placement of the board,
        we backtrack when:
            all positions on a row has been exhausted and none of them are valid.
        output the board when a position at last row has been identified as valid.

        :param n: the size of the board
        :return: List[List[str]]
        """
        queens = [-1] * n
        solutions = []

        self._backtrack(queens, 0, solutions)
        return solutions


sol = Solution()
print(sol.solveNQueens(4))
print(sol.solveNQueens(8))
