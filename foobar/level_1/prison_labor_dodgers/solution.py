def answer(x, y):
    xset = set(x)
    yset = set(y)
    if len(x) > len(y):
        diff = xset - yset
    else:
        diff = yset - xset

    return diff.pop()


if __name__ == '__main__':
    # x = [13, 5, 6, 2, 5]
    # y = [5, 2, 5, 13]
    x = [14, 27, 1, 4, 2, 50, 3, 1]
    y = [2, 4, -4, 3, 1, 1, 14, 27, 50]
    print answer(x, y)
