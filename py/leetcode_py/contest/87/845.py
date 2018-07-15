class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        left = [i for i in range(n)]
        right = [i for i in range(n)]

        for i in range(1, n):
            if A[i-1] < A[i]:
                left[i] = left[i-1]

        for i in range(1, n):
            if A[n-i-1] > A[n-i]:
                right[n-i-1] = right[n-i]

        ret = 0
        for index, item in enumerate(zip(left, right)):
            if item[1] != index and item[0] != index:
                ret = max(ret, item[1] - item[0])

        if ret > 0:
            return ret + 1
        return 0


sol = Solution()
print(sol.longestMountain([2,1,4,7,3,2,5]))
print(sol.longestMountain([2,3]))