class Solution:
    def __init__(self):
        self.min_moves = 400

    def snakesAndLadders(self, board):
        """
        Wrong attempt!
        DFS

        :type board: List[List[int]]
        :rtype: int
        """
        N = len(board)

        def dfs(square, moves, seen):
            print(square, moves)
            # if square == 35:
            #     print(moves, seen)

            # if square == 13:
            #     print(moves)

            if square in seen:
                return

            start_r = N - 1 - (square - 1) // N
            if start_r % 2:
                start_c = (square - 1) % N
            else:
                start_c = N - 1 - (square - 1) % N

            if start_r == 0 and start_c == 0:
                print(moves, self.min_moves)
                self.min_moves = min(self.min_moves, moves)
                # if self.min_moves == 4:
                #     exit(0)
                return

            seen.add(square)
            for i in range(1, 7):
                dest_square = square + i
                if dest_square > N * N or dest_square in seen:
                    continue

                r = N - 1 - (dest_square - 1) // N
                if r % 2:
                    c = (dest_square - 1) % N
                else:
                    c = N - 1 - (dest_square - 1) % N

                if board[r][c] == -1:
                    if square == 35 and dest_square == 36:
                        print('ready to reach final dest! moves = ', moves)

                    dfs(dest_square, moves + 1, seen)
                else:
                    if board[r][c] == 35:
                        print('jumping to 35, moves = ', moves, seen)
                    dfs(board[r][c], moves + 1, seen)
            seen.remove(square)

        seen = set()
        dfs(1, 0, seen)
        return self.min_moves


class Solution2:
    def snakesAndLadders(self, board):
        """
        BFS, brute force

        :type board: List[List[int]]
        :rtype: int
        """
        from queue import Queue

        N = len(board)
        dists = [N * N] * (N * N)
        q = Queue()
        q.put((1, 0))
        while not q.empty():
            square, move = q.get()
            if dists[square-1] > move:
                dists[square-1] = move
                for i in range(1, 7):
                    next_square = square + i
                    if next_square > N * N:
                        break
                    r = N - 1 - (next_square - 1) // N
                    if r % 2 != N % 2:
                        c = (next_square - 1) % N
                    else:
                        c = N - 1 - (next_square - 1) % N

                    # print(next_square, r, c)
                    if board[r][c] != -1:
                        q.put((board[r][c], move + 1))
                    else:
                        q.put((next_square, move + 1))

        # print(dists)
        if dists[N*N - 1] == N * N:
            return -1
        return dists[N*N - 1]

    def snakesAndLadders2(self, board):
        """
        BFS, improved with early termination

        :type board: List[List[int]]
        :rtype: int
        """
        from collections import deque

        N = len(board)
        dists = [N * N] * (N * N)
        q = deque()
        q.append((1, 0))
        while q:
            square, move = q.popleft()
            # print(square, move)
            if dists[square-1] > move:
                dists[square-1] = move
                if square == N * N:
                    return move
                for i in range(1, 7):
                    next_square = square + i
                    if next_square > N * N:
                        break
                    r = N - 1 - (next_square - 1) // N
                    if r % 2 != N % 2:
                        c = (next_square - 1) % N
                    else:
                        c = N - 1 - (next_square - 1) % N

                    # print(next_square, r, c)
                    if board[r][c] != -1:
                        q.append((board[r][c], move + 1))
                    else:
                        q.append((next_square, move + 1))

        # print(dists)
        return -1


sol = Solution2()
board = [
    [-1,-1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,-1],
    [-1,35,-1,-1,13,-1],
    [-1,-1,-1,-1,-1,-1],
    [-1,15,-1,-1,-1,-1]
]
print(sol.snakesAndLadders2(board))  # 4

board2 = [[4, -1], [-1, 3]]
print(sol.snakesAndLadders2(board2))  # 1

board3 = [[1,1,-1],[1,1,1],[-1,1,1]]
print(sol.snakesAndLadders2(board3))  # -1

board4 = [[-1,-1,19,10,-1],[2,-1,-1,6,-1],[-1,17,-1,19,-1],[25,-1,20,-1,-1],[-1,-1,-1,-1,15]]
print(sol.snakesAndLadders2(board4))  # 2
