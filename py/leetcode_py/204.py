class Solution:
    def isprime(self, m):
        import math
        for i in range(2, math.floor(math.sqrt(m)) + 1):
            if m % i == 0:
                return False
        return True

    def countPrimes(self, n):
        """
        time: O(n^1.5)

        :type n: int
        :rtype: int
        """
        count = 0
        for i in range(2, n):
            if self.isprime(i):
                count += 1

        return count

    def isprime2(self, m, primes):
        for p in primes:
            if m % p == 0:
                return False
        return True

    def countPrimes2(self, n):
        """
        time: ?

        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0

        count = 1
        primes = [2]
        for i in range(3, n):
            if self.isprime2(i, primes):
                count += 1
                primes.append(i)

        return count

    def countPrimes3(self, n):
        """
        Sieve of Eratosthenes: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

        :type n: int
        :rtype: int
        """
        marked_list = [[i, False] for i in range(2, n)]
        cur_prime = 2
        start_index = cur_prime ** 2 - 2
        while cur_prime ** 2 < n:
            # print(cur_prime, start_index)
            for item in marked_list[start_index:]:
                if not item[1] and item[0] % cur_prime == 0:
                    item[1] = True

            for index, item in enumerate(marked_list):
                if not item[1] and item[0] > cur_prime:
                    cur_prime = item[0]
                    start_index = cur_prime ** 2 - 2
                    break

        primes = [item[0] for item in marked_list if item[1] is False]
        return len(primes)

    def countPrimes4(self, n):
        """
        Sieve of Eratosthenes: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

        :type n: int
        :rtype: int
        """
        marked_list = [[i, False] for i in range(2, n)]
        cur_prime = 2
        while cur_prime ** 2 < n:
            next = cur_prime ** 2
            while next < n:
                marked_list[next - 2][1] = True
                next += cur_prime

            for item in marked_list:
                if not item[1] and item[0] > cur_prime:
                    cur_prime = item[0]
                    break

        primes = [item[0] for item in marked_list if item[1] is False]
        return len(primes)

    def countPrimes5(self, n):
        """
        Sieve of Eratosthenes: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

        :type n: int
        :rtype: int
        """
        marks = [False] * (n - 2)
        p = 2
        start = p ** 2
        while start < n:
            while start < n:
                marks[start - 2] = True
                start += p

            for index, mark in enumerate(marks, start=2):
                if mark is False and index > p:
                    p = index
                    start = p ** 2
                    break

        return marks.count(False)

    def countPrimes6(self, n):
        """
        Sieve of Eratosthenes: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

        :type n: int
        :rtype: int
        """
        isprime = [True] * n
        p = 2
        while p ** 2 < n:
            if isprime[p] is False:
                p += 1
                continue

            start = p ** 2
            while start < n:
                isprime[start] = False
                start += p

            p += 1

        return isprime.count(True) - 2 if n >= 2 else 0  # exclude 0 and 1


if __name__ == '__main__':
    sol = Solution()
    print(sol.countPrimes(10))  # 4

    print(sol.countPrimes2(10))  # 4
    # print(sol.countPrimes(499999))  # 41538

    print(sol.countPrimes4(10))  # 4
    # print(sol.countPrimes4(499999))  # 41538
    # print(sol.countPrimes4(1500000))  # 114155

    print(sol.countPrimes5(10))  # 4
    print(sol.countPrimes5(499999))  # 41538
    print(sol.countPrimes5(1500000))  # 114155

    print(sol.countPrimes6(10))  # 4
    print(sol.countPrimes6(499999))  # 41538
    print(sol.countPrimes6(1500000))  # 114155