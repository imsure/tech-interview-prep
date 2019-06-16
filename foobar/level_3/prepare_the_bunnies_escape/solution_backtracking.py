import sys

class Result:
    def __init__(self):
        self.min_len = sys.maxint
        self.abs_min_found = False


def explore(maze, h, w, r, c, count, res, visited):
    if res.abs_min_found or r < 0 or r >= h or c < 0 or c >= w or maze[r][c] == 1 or visited[r][c]:
        return

    visited[r][c] = True
    count += 1
    # print count
    if r == h-1 and c == w-1:
        res.min_len = min(res.min_len, count)
        if count == h + w - 1:
            res.abs_min_found = True
        return

    explore(maze, h, w, r - 1, c, count, res, visited)
    explore(maze, h, w, r + 1, c, count, res, visited)
    explore(maze, h, w, r, c - 1, count, res, visited)
    explore(maze, h, w, r, c + 1, count, res, visited)
    visited[r][c] = False


def answer(maze):
    h = len(maze)
    w = len(maze[0])

    res = Result()
    ans = sys.maxint
    visited = []
    for i in xrange(0, h):
        visited.append([])
        for j in xrange(0, w):
            visited[i].append(False)

    explore(maze, h, w, 0, 0, 0, res, visited)
    ans = min(ans, res.min_len)
    if res.abs_min_found:
        return res.min_len

    for i in xrange(0, h):
        for j in xrange(0, w):
            if maze[i][j] == 1:
                res = Result()
                maze[i][j] = 0
                for m in xrange(0, h):
                    for n in xrange(0, w):
                        visited[m][n] = False

                explore(maze, h, w, 0, 0, 0, res, visited)
                ans = min(ans, res.min_len)
                if res.abs_min_found:
                    return res.min_len
                maze[i][j] = 1

    return ans


if __name__ == '__main__':
    maze = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
    print answer(maze)  # expected 7

    maze = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
    print answer(maze)  # expected 11
