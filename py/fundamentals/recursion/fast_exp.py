def fast_exp(a, n):
    """
    Compute a^n using recursion.

    :param a:
    :param n:
    :return:
    """
    if n <= 1:
        return a

    m = n // 2
    a1 = fast_exp(a, m)
    a2 = a1
    if n % 2:
        a2 *= a
    return a1 * a2


print(fast_exp(2, 5))
print(fast_exp(5, 4))