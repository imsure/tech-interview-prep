def answer(M, F):
    m = int(M)
    f = int(F)

    step = 0
    while m != f and m != 0 and f != 0:
        if m == 1:
            step += f - 1
            f = 1
            break
        if f == 1:
            step += m - 1
            m = 1
            break

        if m > f:  # if m > f, M must be replicated from F in the previous step
            inc = int(round(m / f))
            m = m - f * inc
            step += inc
        else:  # if m < f, F must be replicated from M in the previous step
            inc = int(round(f / m))
            f = f - m * inc
            step += inc

    if m == f == 1:
        return step
    return 'impossible'


if __name__ == '__main__':
    print(answer('1', '1'))  # '0'
    print(answer('2', '2'))  # 'impossible'
    print(answer('2', '1'))  # '1'
    print(answer('2', '1'))  # '1'
    print(answer('4', '1'))  # '3'
    print(answer('1', '4'))  # '3'
    print(answer('3', '8'))  # '4'
    print(answer('7', '4'))  # '4'
