def hanoi(n, src, tmp, dest):
    if n == 0:
        return

    if n == 1:
        dest.append(src.pop())
        return

    hanoi(n - 1, src, dest, tmp)
    dest.append(src.pop())
    hanoi(n - 1, tmp, src, dest)


# improved code quality
def hanoi2(n, src, tmp, dest):
    if n > 0:
        hanoi(n - 1, src, dest, tmp)
        top = src.pop()
        if dest == [] or dest[len(dest) - 1] > top:  # enforce the rule
            dest.append(top)
        hanoi(n - 1, tmp, src, dest)


src, tmp, dest = [i for i in range(10, 0, -1)], [], []
print(dest)
hanoi2(len(src), src, tmp, dest)
print(dest)


