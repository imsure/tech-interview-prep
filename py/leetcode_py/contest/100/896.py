class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        diff = [0]
        for i in range(len(A) - 1):
            diff.append(A[i] - A[i+1])

        pred_pos = [d >= 0 for d in diff]
        pred_neg = [d <= 0 for d in diff]

        return all(pred_neg) or all(pred_pos)


sol = Solution()
print(sol.isMonotonic([1,2,2,3]))
print(sol.isMonotonic([6,5,4,4]))
print(sol.isMonotonic([1,3,2]))
print(sol.isMonotonic([1,2,4,5]))
print(sol.isMonotonic([1,1,1]))

