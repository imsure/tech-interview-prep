import sys
import heapq


def dijkstra(maze, h, w):
    pq = []
    heapq.heappush(pq, (0, 0, 0))  # initialize source distance

    visited = set()
    offsets = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    while pq:
        dist, r, c = heapq.heappop(pq)
        if (r, c) in visited:
            continue

        visited.add((r, c))
        if r == h - 1 and c == w - 1:
            return dist + 1

        for offset in offsets:
            rn, cn = r + offset[0], c + offset[1]
            if 0 <= rn < h and 0 <= cn < w and maze[rn][cn] == 0 and (rn, cn) not in visited:
                distn = dist + 1
                heapq.heappush(pq, (distn, rn, cn))

    return sys.maxint


def is_valid(maze, r, c, h, w):
    if r + 1 < h and maze[r+1][c] == 0:
        return True
    if r - 1 >= 0 and maze[r-1][c] == 0:
        return True
    if c + 1 < w and maze[r][c+1] == 0:
        return True
    if c - 1 >= 0 and maze[r][c-1] == 0:
        return True

    return False


def answer(maze):
    h = len(maze)
    w = len(maze[0])

    ans = sys.maxint
    ans = min(ans, dijkstra(maze, h, w))
    if ans == h + w - 1:
        return ans

    for i in xrange(0, h):
        for j in xrange(0, w):
            if maze[i][j] == 1 and is_valid(maze, i, j, h, w):
                maze[i][j] = 0
                ans = min(ans, dijkstra(maze, h, w))
                if ans == h + w - 1:
                    return ans
                maze[i][j] = 1

    return ans


if __name__ == '__main__':
    maze = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
    print answer(maze)  # expected 7

    maze = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
    print answer(maze)  # expected 11
