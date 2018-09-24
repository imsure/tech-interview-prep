class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        x, y = A[0], A[len(A) - 1]
        return max(0, y - x - 2*K)