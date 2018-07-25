def first_greater_than(A, t):
    """
    Return the index of the first element in sorted array A that is greater than t.

    :param A:
    :param t:
    :return:
    """
    if len(A) == 0:
        return -1

    lo, hi = 0, len(A) - 1

    while lo < hi:
        mid = lo + (hi - lo) // 2
        if A[mid] <= t:
            lo = mid + 1
        else:
            hi = mid

    if A[lo] > t:
        return lo

    return -1


def find_median(A, B):
    """
    Problem 3:
    Find the median of the two sorted array A and B, both are of equal length.

    :param A:
    :param B:
    :return:
    """
    # print(A, B)
    if len(A) <= 2 or len(B) <= 2:  # brute force
        tmp = []
        i, j = 0, 0
        m, n = len(A), len(B)
        while i < m and j < n:
            if A[i] <= B[j]:
                tmp.append(A[i])
                i += 1
            else:
                tmp.append(B[j])
                j += 1

        tmp += A[i:]
        tmp += B[j:]

        return tmp[1]

    mid_A = (len(A) - 1) // 2
    mid_B = (len(B) - 1) // 2

    # print(A[mid_A], B[mid_B])
    if A[mid_A] == B[mid_B]:
        return mid_A
    elif A[mid_A] < B[mid_B]:
        return find_median(A[mid_A+1:], B[:mid_B+1])
    else:
        return find_median(A[:mid_A+1], B[mid_B+1:])


A = [0, 1, 6, 9, 12, 13, 18, 20]
B = [2, 4, 5, 8, 17, 19, 21, 23]
print(find_median(A, B))  # expected: 9

A = [1, 2, 3, 4, 5]
B = [6, 7, 8, 9, 10]
print(find_median(A, B))  # expected: 5

B = [1, 2, 3, 4, 5]
A = [6, 7, 8, 9, 10]
print(find_median(A, B))  # expected: 5

A = [1]
B = [2]
print(find_median(A, B))  # expected: 1

A = [1, 3]
B = [2, 4]
print(find_median(A, B))  # expected: 2

A = [1, 1, 1]
B = [1, 1, 1]
print(find_median(A, B))  # expected: 1

A = [1, 2, 3]
B = [3, 3, 3]
print(find_median(A, B))  # expected: 3

A = [1, 2, 2]
B = [3, 3, 3]
print(find_median(A, B))  # expected: 2
