class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in range(0, len(A)):
            A[i] = A[i][::-1]

        for i in range(0, len(A)):
            for j in range(0, len(A[0])):
                if A[i][j] == 0:
                    A[i][j] = 1
                else:
                    A[i][j] = 0

        return A


if __name__ == '__main__':
    sol = Solution()
    print(sol.flipAndInvertImage([[1,1,0],[1,0,1],[0,0,0]]))