def fib(n):
    if n < 2:
        return n

    fib_0 = 0
    fib_1 = 1
    fib_2 = 0
    while n >= 2:
        fib_2 = fib_0 + fib_1
        fib_0 = fib_1
        fib_1 = fib_2
        n -= 1

    return fib_2


# improve code quality
def fib2(n):
    prev = 1
    cur = 0

    for i in range(1, n+1):
        _next = prev + cur
        prev = cur
        cur = _next

    return cur
