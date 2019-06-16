def answer(x, y):
    # locate the point (1, y)
    inc = 0
    row_start = 1
    for i in xrange(0, y):
        row_start += inc
        inc += 1

    # locate the point (x, y)
    inc += 1
    for i in xrange(1, x):
        row_start += inc
        inc += 1

    return str(row_start)


if __name__ == '__main__':
    print answer(3, 2)
    print answer(5, 10)
