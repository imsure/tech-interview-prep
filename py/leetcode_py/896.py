class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        n = len(A)
        return all([A[i] <= A[i+1] for i in range(n-1)]) or all([A[i] >= A[i+1] for i in range(n-1)])

    def isMonotonic2(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        n = len(A)
        trend = 0
        for i in range(n-1):
            if A[i] < A[i+1]:
                if trend == 0:
                    trend = -1
                elif trend == 1:
                    return False
            elif A[i] > A[i+1]:
                if trend == 0:
                    trend = 1
                elif trend == -1:
                    return False

        return True

    def isMonotonic3(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        n = len(A)
        trend = 0
        for i in range(n-1):
            if A[i] < A[i+1]:
                cmp = -1
            elif A[i] > A[i+1]:
                cmp = 1
            else:
                cmp = 0

            if cmp:
                if cmp != trend != 0:
                    return False
                trend = cmp

        return True

    def isMonotonic4(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        n = len(A)
        inc, dec = True, True
        for i in range(n-1):
            if A[i] < A[i+1]:
                dec = False
            elif A[i] > A[i+1]:
                inc = False

        return inc or dec


sol = Solution()
print(sol.isMonotonic4([1,2,2,3]))  # true
print(sol.isMonotonic4([6,5,4,4]))  # true
print(sol.isMonotonic4([1,3,2]))  # false
print(sol.isMonotonic4([1,1,1]))  # true
