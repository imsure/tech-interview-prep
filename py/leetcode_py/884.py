class Solution:
    def decodeAtIndex(self, S, K):
        """
        Intuition: for string "appleapple" with "apple" repeated 2 times and K = 9, the answer
        is equivalent to the same problem with string "apple" and K = 9 % 5 = 4, thus 'l'.

        Calculate the length (N) of S until N >= K, then work backwards from
        current S[i] to S[0].

        - if S[i] is a digit d, that means the string S[0]...S[i-1] is repeated d times,
          reduce N = N / d, and K = K % N
        - if S[i] is a char c and K == N or K == 0, return S[i], otherwise reduce N by 1.

        :type S: str
        :type K: int
        :rtype: str
        """
        N = 0
        i = 0
        for c in S:
            if c.isalpha():
                N += 1
            else:
                d = int(c)
                N *= d

            if N >= K:
                break
            i += 1

        while i >= 0:
            if S[i].isdigit():
                d = int(S[i])
                N /= d  # update N
                K %= N  # update K
            elif K == N or K == 0:
                return S[i]
            else:
                N -= 1

            i -= 1

        return None


sol = Solution()
print(sol.decodeAtIndex("leet2code3", 10))  # o
print(sol.decodeAtIndex("ha22", 5))  # h
print(sol.decodeAtIndex("a2345678999999999999999", 1))  # a
