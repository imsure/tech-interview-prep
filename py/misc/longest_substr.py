def longest_substr(A, B):
    """
    Define dp[i][j] as: whether substr B[0...j] and substr A[i-j, j] match or not, where i >= j

    dp[i][j] = True if A[i] == B[j] and dp[i-1][j-1] is True and i >= j > 0
             = False if A[i] != B[j]

    :param A:
    :param B:
    :return:
    """
    n, m = len(A), len(B)

    dp = []
    for i in range(n):
        dp.append([])
        for j in range(m):
            dp[i].append(False)

    max_j = 0
    for i in range(n):
        for j in range(m):
            if i >= j and A[i] == B[j]:
                if j == 0:
                    dp[i][j] = True
                elif dp[i-1][j-1]:
                    dp[i][j] = True
                    max_j = max(max_j, j)

    ans = []
    for i in range(n):
        if i >= max_j and dp[i][max_j]:
            ans.append((i-max_j, max_j + 1))

    return ans


print(longest_substr('FOOFOOD', 'FOO'))
print(longest_substr('FOOFOOD', 'FOOD'))
print(longest_substr('FOOFOOD', 'FOOX'))
print(longest_substr('FOOFOOD', 'XYZ'))
print(longest_substr('FOOBAR', 'BARFOO'))
print(longest_substr('XXYZZZ', 'XYZ'))