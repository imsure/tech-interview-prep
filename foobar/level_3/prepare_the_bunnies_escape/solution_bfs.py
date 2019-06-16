from Queue import Queue
import sys

class Label:
    def __init__(self):
        self.visited = False
        self.dist = 1


def bfs(maze, h, w):
    labels = []
    for i in xrange(0, h):
        labels.append([])
        for j in xrange(0, w):
            labels[i].append(Label())

    queue = Queue()
    queue.put((0, 0))
    labels[0][0].visited = True
    while not queue.empty():
        item = queue.get()
        r, c = item[0], item[1]
        label = labels[r][c]
        if r + 1 < h and maze[r+1][c] == 0 and labels[r+1][c].visited == False:
            queue.put((r + 1, c))
            labels[r+1][c].visited = True
            labels[r+1][c].dist = label.dist + 1
            if r + 1 == h - 1 and c == w - 1:
                return labels[r+1][c].dist

        if c + 1 < w and maze[r][c+1] == 0 and labels[r][c+1].visited == False:
            queue.put((r, c + 1))
            labels[r][c+1].visited = True
            labels[r][c+1].dist = label.dist + 1
            if r == h - 1 and c + 1 == w - 1:
                return labels[r][c+1].dist

        if r - 1 >= 0 and maze[r-1][c] == 0 and labels[r-1][c].visited == False:
            queue.put((r - 1, c))
            labels[r-1][c].visited = True
            labels[r-1][c].dist = label.dist + 1

        if c - 1 >= 0 and maze[r][c-1] == 0 and labels[r][c-1].visited == False:
            queue.put((r, c - 1))
            labels[r][c-1].visited = True
            labels[r][c-1].dist = label.dist + 1

    return labels[h-1][w-1].dist


def answer(maze):
    h = len(maze)
    w = len(maze[0])

    ans = sys.maxint
    ans = min(ans, bfs(maze, h, w))
    if ans == h + w - 1:
        return ans

    for i in xrange(0, h):
        for j in xrange(0, w):
            if maze[i][j] == 1:
                maze[i][j] = 0
                ans = min(ans, bfs(maze, h, w))
                if ans == h + w - 1:
                    return ans
                maze[i][j] = 1

    return ans



if __name__ == '__main__':
    maze = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
    print answer(maze)  # expected 7

    maze = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
    print answer(maze)  # expected 11
