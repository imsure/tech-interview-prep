class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        i = 0
        while i < len(A) - 1:
            if A[i] > A[i+1]:
                return i
            i += 1

        return -1


sol = Solution()
print(sol.peakIndexInMountainArray([0,1,0]))
print(sol.peakIndexInMountainArray([0,2,1,0]))