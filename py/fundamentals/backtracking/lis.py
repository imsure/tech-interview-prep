"""
Brute-force approach to Longest Increasing Subsequence problem
using recursion.
"""


def _lis(A, prev):
    """
    Returns the length of LIS in A where each element of LIS is greater than `prev`.

    :param A:
    :param prev:
    :return:
    """
    if len(A) == 0:
        return 0

    m1 = _lis(A[1:], prev)  # LIS not including A[0]
    if A[0] > prev:
        m2 = 1 + _lis(A[1:], A[0])
        return max(m1, m2)
    else:
        return m1


def lis_rec(A):
    """
    For each element in the array, it is either in the LIS or not.
    We can recursively try out all possible combinations and find
    the optimal one.

    Time: O(2^n), n is the length of A.

    :param A:
    :return:
    """
    import sys
    return _lis(A, -sys.maxsize)


print(lis_rec([]))
print(lis_rec([10,9,2,5,3,7,101,18]))  # 4
print(lis_rec([1, 2, 3, 4, 5]))  # 5
print(lis_rec([5, 3, 1]))  # 1
