import math

# Handout formula: 1 + 2 + 4 + 8 + ... 2^k = 2^(k+1) - 1
# Given total_lambs, we just need to figure out k in constant time
def generous_handout(total_lambs):
    return int(math.floor(math.log(total_lambs + 1, 2)))


# Return the n_th fibonacci number
def fib(n):
    matrix = [[1, 1], [1, 0]]
    matrix_power(matrix, n-1)
    return matrix[0][0]


def matrix_power(matrix, n):
    if n == 0 or n == 1:
        return

    M = [[1, 1], [1, 0]]
    matrix_power(matrix, n // 2)
    matrix_multiply(matrix, matrix)

    if n % 2:
        matrix_multiply(matrix, M)


def matrix_multiply(M1, M2):
    v1 = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0]
    v2 = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1]
    v3 = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0]
    v4 = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1]

    M1[0][0] = v1
    M1[0][1] = v2
    M1[1][0] = v3
    M1[1][1] = v4


# Handout formula: 1, 1, 2, 3, 5, 8, ... which is a fibonacci series.
# Since we have sum_of_first_n_fib_nums = fib(n+2) - fib(1) and fib(1) = 1,
# therefore we just need to find the biggest fibonacci number <= total_lambs + 1.
# we use binary search to find this number in log time.
def stingy_handout(total_lambs, lower_bound):
    target = total_lambs + 1
    lo = lower_bound
    hi = total_lambs
    while lo <= hi:
        mid = (lo + hi) // 2
        fib_mid = fib(mid)
        # print 'lo: {}, hi: {}, mid: {}, fib_mid: {}'.format(lo, hi, mid, fib_mid)
        if fib_mid > target:
            hi = mid - 1
        elif fib_mid == target:
            return mid - 2
        else:
            if fib(mid+1) > target:
                return mid - 2
            else:
                lo = mid + 1

    return lo - 2


def answer(total_lambs):
    min_num = generous_handout(total_lambs)
    print(min_num)
    max_num = stingy_handout(total_lambs, min_num)
    return max_num - min_num


if __name__ == '__main__':
    # for i in range(1, 10):
    #    print fib(i)

    print answer(10)  # expected: 3, 4
    print answer(143)  # expected: 7, 10
    print answer(1e8)  # expected:
