def lis(A):
    """
    Contains bug!
    Return the longest increasing subsequence of array A.

    :param A:
    :return:
    """
    import sys

    n = len(A)
    if n == 0:
        return 0

    T = []
    for i in range(n+1):
        T.append([0] * (n+1))

    for j in range(n-1, -1, -1):
        for i in range(0, j):
            if i == 0:
                prev = -sys.maxsize
            else:
                prev = A[i-1]

            if A[j] <= prev:
                T[i][j] = T[i][j+1]
            else:
                T[i][j] = max(T[i][j+1], 1 + T[j][j+1])

    print(T)
    return T[0][1]


def lis2(A):
    """
    Return the longest increasing subsequence of array A.

    :param A:
    :return:
    """
    import sys

    n = len(A)
    if n == 0:
        return 0

    A.insert(0, -sys.maxsize)

    T = []
    for i in range(n+1):
        T.append([0] * (n+2))

    for j in range(n, 0, -1):
        for i in range(0, j):
            if A[i] >= A[j]:
                T[i][j] = T[i][j+1]
            else:
                T[i][j] = max(T[i][j+1], 1 + T[j][j+1])

    # print(T)
    return T[0][1]


def lis3(A):
    """
    Return the longest increasing subsequence of array A.

    LIS[i]: LIS of A[i...n] that starts with i
    LIS[i] = 1 + max{LIS[j] | j > i and A[j] > A[i]}

    time: O(n^2)
    space: O(n)

    :param A:
    :return:
    """
    n = len(A)
    if n == 0:
        return 0

    dp = [0] * n
    dp[n-1] = 1
    ans = 1
    for i in range(n-2, -1, -1):
        m = 0
        for j in range(i, n):
            if A[j] > A[i]:
                m = max(m, dp[j])
        dp[i] = 1 + m
        ans = max(ans, dp[i])

    return ans


print(lis3([1, 2, 3]))  # 3
print(lis3([5, 4, 3, 2, 1]))  # 1
print(lis3([4, 2, 3, 1, 5, 7, 8]))  # 5
print(lis3([4, 2, 0, 8, 5, 7, 8]))  # 4
print(lis3([4,4,4,3]))  # 1
print(lis3([4,4,4,4]))  # 1
print(lis3([4,10,4,3,8,9]))  # 3
print(lis3([5,3,8,9]))  # 3
print(lis3([10, 9, 2, 5, 3, 7, 101, 18]))  # 4
