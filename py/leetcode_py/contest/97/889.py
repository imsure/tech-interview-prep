class Solution:
    def _valid(self, R, C, r, c):
        return 0 <= r < R and 0 <= c < C

    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        N = R * C
        count = 0
        ans = []

        p = 2
        d = 1
        start = [r0, c0]
        ans.append(start)
        count = 1
        while count < N:
            r, c = start
            # if self._valid(R, C, r, c):
            #     ans.append(start)
            #     count += 1

            if d > 0:
                for i in range(1, p):
                    if self._valid(R, C, r, c + i):
                        ans.append([r, c+i])
                        count += 1
                c = c + p - 1
                for i in range(1, p):
                    if self._valid(R, C, r + i, c):
                        ans.append([r+i, c])
                        count += 1

                r = r + p - 1
                start = [r, c]
                d = -1
            else:
                for i in range(1, p):
                    if self._valid(R, C, r, c - i):
                        ans.append([r, c-i])
                        count += 1
                c = c - p + 1
                for i in range(1, p):
                    if self._valid(R, C, r - i, c):
                        ans.append([r-i, c])
                        count += 1

                r = r - p + 1
                start = [r, c]
                d = 1

            p += 1

        return ans


sol = Solution()
print(sol.spiralMatrixIII(1, 4, 0, 0))
print(sol.spiralMatrixIII(5, 6, 1, 4))