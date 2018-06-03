class Solution:
    def countSubstrings(self, s):
        """
        DP:
        let len(s) be n. Initialize a n * n table T of booleans with diagonal cells
        filled with true indicating substr[i...i] are palindromes. Then fill the table
        following the diagonal direction.

        The DP formula is T[i...j] == true if T[i+1, j-1] is True and S[i] == S[j].

        :type s: str
        :rtype: int
        """
        n = len(s)
        count = n

        table = [[False for _ in range(n)] for _ in range(n)]
        for i in range(n):
            table[i][i] = True

        for d in range(1, n):
            for r in range(0, n-d):
                c = r + d
                if s[r] != s[c]:
                    table[r][c] = False
                else:
                    table[r][c] = True
                    count += 1
                    if c - 1 >= r + 1 and table[r+1][c-1] is False:
                        table[r][c] = False
                        count -= 1

        return count


if __name__ == '__main__':
    sol = Solution()
    print(sol.countSubstrings('aaa'))  # 6
    print(sol.countSubstrings('abc'))  # 3
    print(sol.countSubstrings(''))  # 0