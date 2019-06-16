def answer(M, F):
    m = int(M)
    f = int(F)

    step = 0
    while m != f:
        if m > f:  # if m > f, M must be replicated from F in the previous step
            m -= f
        else:  # if m < f, F must be replicated from M in the previous step
            f -= m
        step += 1

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
