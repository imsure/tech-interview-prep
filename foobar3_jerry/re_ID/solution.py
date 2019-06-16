import math

def is_prime(p):
    for i in range(2, int(math.sqrt(p)) + 1):
        if p % i == 0:
            return False

    return True

def answer(n):
    prime_str = ''
    p = 2
    while True:
        if len(prime_str) > n + 4:
            return prime_str[n:n+5]

        if is_prime(p):
            prime_str += str(p)

        p += 1


if __name__ == '__main__':
    print(answer(0))
    print(answer(3))
    print(answer(3))
    print(answer(11))  # 92329
    print(answer(10000))
